# frozen_string_literal: true

# begin x509 connection
require 'mongo'

client = Mongo::Client.new(
  ['mongodb+srv://<cluster-url>/test'],
  auth_mech: :mongodb_x509,
  ssl: true,
  ssl_cert: '/etc/certs/mongodb/client.pem',
  ssl_key: '/etc/certs/mongodb/client.pem'
)
db = client.database[:testDB]
collection = client[:testCol]
docCount = collection.count_documents({})
print docCount
# end x509 connection