# begin scram connection
require 'mongo'

client = Mongo::Client.new('mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority')
# end scram connection