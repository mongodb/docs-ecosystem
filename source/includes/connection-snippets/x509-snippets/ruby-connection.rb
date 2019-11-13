# begin x509 connection
require 'mongo'

begin
  client = Mongo::Client.new( 
                             ['localmongo1:27017'],
                             auth_mech: :mongodb_x509,
                             ssl: true,
                             ssl_cert:    '/Users/<user>/dev/x509-driver-snippets/certs/test-client.pem',
                             ssl_key:    '/Users/<user>/dev/x509-driver-snippets/certs/test-client.pem',
                             ssl_ca_cert: '/Users/<user>/dev/x509-driver-snippets/certs/test-ca.pem',

                            )

  puts Thread.current.backtrace

  db = client.database[:test]
  collection = client[:stuff]

  doc = { name: 'Ruby', hobbies: [ 'hiking', 'tennis', 'fly fishing' ] }

  result = collection.insert_one(doc)
  puts result.n
rescue StandardError => e
  puts e.backtrace
end

# end x509 connection