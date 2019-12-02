# begin scram connection
import pymongo

client = pymongo.MongoClient(
   "mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority")
   
db = client['testDB']
collection = db['testCol']
docCount = collection.count_documents({})
print(docCount)
# end scram connection