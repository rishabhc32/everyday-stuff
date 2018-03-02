import re
import os
import quopri
import imaplib
import string as st
from email.policy import default
from email.parser import Parser
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.keys import Keys as keys

def get_email():
	if not hasattr(get_email, 'current_email'):
		get_email.alphabets = list(st.ascii_lowercase)
		get_email.alphabets = get_email.alphabets[9:]
		get_email.current_email = -1
	
	get_email.current_email += 1
	ans = get_email.alphabets[get_email.current_email]+get_email.alphabets[get_email.current_email]
	
	return ans

def signup(browser, email):
	browser.get('https://devrant.com//feed/top/month?signup=1')

	element = browser.find_element_by_name('email')
	element.clear()
	element.send_keys(email + os.getenv('DOMAIN'))

	element = browser.find_element_by_name('username')
	element.clear()
	element.send_keys(email+'rc32')

	element = browser.find_element_by_name('password')
	element.clear()
	element.send_keys(os.getenv('PASSWORD'))
	
	element = browser.find_element_by_class_name('signup-email-btn')
	element.click()

def login(browser, email):
	browser.get('https://devrant.com/feed/top/month?login=1')

	element = browser.find_elements_by_name('email')
	element = element[1]
	element.clear()
	element.send_keys(email+'rc32')

	element = browser.find_elements_by_name('password')
	element = element[1]
	element.clear()
	element.send_keys(os.getenv('PASSWORD'))

	element = browser.find_elements_by_class_name('signup-email-btn')
	element = element[1]
	element.click()
	

def got_new_email(imap_connection):
	res, ans = imap_connection.select('INBOX', readonly=True)
	current_email = int(ans[0].decode('ascii'))

	while current_email <= got_new_email.last_email:
		res, ans = imap_connection.select('INBOX', readonly=True)
		current_email = int(ans[0].decode('ascii'))

	got_new_email.last_email = current_email
	return True

def get_confirmation(imap_connection, browser):
	typ, msg_data = imap_connection.fetch(str(got_new_email.last_email), ('RFC822'))
	msg_data = quopri.decodestring(msg_data[0][1]).decode('utf-8', errors='replace')
	msg = Parser(policy=default).parsestr(msg_data)

	soup = BeautifulSoup(msg.get_content(), 'lxml')
	tag = soup.find_all('a', string=re.compile('Verify'))[0]

	browser.get(tag['href'])

def upvote(browser):
	browser.get('https://devrant.com/rants/1234898/turboc-why-dont-colleges-get-rid-of-this-shit')
	element = browser.find_element_by_class_name('btn-vote-circle')
	try:
		element.click()
	except Exception as e:
		element = browser.find_element_by_class_name('modal-x')
		element.click()
		browser.get('https://devrant.com/rants/1234898/turboc-why-dont-colleges-get-rid-of-this-shit')
		element = browser.find_element_by_class_name('btn-vote-circle')
		element.click()

	

if __name__ == '__main__':
	host = os.getenv('IMAP_HOST')
	user = os.getenv('IMAP_USER')
	pswd = os.getenv('IMAP_PSSWD')

	imap_connection = imaplib.IMAP4_SSL(host)
	imap_connection.login(user, pswd)

	res, got_new_email.last_email = imap_connection.select('INBOX', readonly=True)
	got_new_email.last_email = int(got_new_email.last_email[0].decode('ascii'))

	browser = webdriver.Firefox()

	for s in range(11):
		email = get_email()
		signup(browser, email)
		login(browser, email)
		got_new_email(imap_connection)
		get_confirmation(imap_connection, browser)
		upvote(browser)

	imap_connection.logout()
