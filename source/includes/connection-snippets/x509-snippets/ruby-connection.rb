#begin x509 connection
require 'mongo'

begin
client = Mongo::Client.new(
  ['localmongo1:27017'],
  auth_mech:: mongodb_x509,
  ssl: true,
  ssl_cert: '/etc/certs/mongodb/client.pem',
  ssl_key: '/etc/certs/mongodb/client.pem',
  ssl_ca_cert: '/etc/certs/mongodb/ca.pem',

)

puts Thread.current.backtrace
rescue StandardError => e
puts e.backtrace
end
# end x509 connection