# begin scram connection
require 'mongo'

client = Mongo::Client.new('mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority', :database => 'testDB')

collection = client[:testCol]
docCount = collection.count_documents({})
print docCount
# end scram connection