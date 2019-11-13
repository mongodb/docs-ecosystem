# begin scram connection
require 'mongo'

client = Mongo::Client.new('mongodb+srv://kay:myRealPassword@cluster0.mongodb.net/?ssl=true&w=majority')
# end scram connection