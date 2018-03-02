# devRant Stickers
So, [devRant](https://devrant.com/) is giving free stickers to everyone who get more than _20++_ on an single rant. 
I wanted the stickers but it would take some time before I can get 20++ on single rant. So I devised a method to create proxy users and _++_ my rant.

In my domain, I setup a _catch-all_ domain which forwards all mails sent on non-exsistent _MX records_. E.g. if an email is sent to a non-exsisting email ID like `email@mydomain.com`, it is forwarded to my default email iD. Therefore, opening possibility of infinite username and email-IDs.

Now, I automated the process of _signup_ and _login_ on devRant using python _selenium webdriver_. Then the user was verified by getting latest mail from default email-ID's _imap_ account and finally going to the particular rant to _++_, using selenium.
