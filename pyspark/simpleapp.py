from pyspark import SparkContext

textFileName = 'yo.txt'
sc = SparkContext('local', 'Simple App')
textFile = sc.textFile(textFileName)

number_of_Hs = textFile.filter(lambda s: 'h' in s).count()

print("Lines with h: %i" % (number_of_Hs))
