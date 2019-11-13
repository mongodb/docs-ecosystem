# begin scram connection
import pymongo

client = pymongo.MongoClient(
   "mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority")
db = client.test
# end scram connection