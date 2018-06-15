from pyspark import SparkContext

def d(s):
    print(type(s))
    return 'h' in s

textFileName = 'yo.txt'
sc = SparkContext('local', 'Simple App')
textFile = sc.textFile(textFileName)

number_of_Hs = textFile.filter(d).count()

print("Lines with h: %i" % (number_of_Hs))
