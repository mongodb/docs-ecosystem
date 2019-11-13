# begin x509 connection
use strict;

use IO::Socket::SSL;
use MongoDB;
 
my $client     = MongoDB::MongoClient->new(
    host => "mongodb://hostname",
    ssl  => {
      SSL_ca_file => "/path/to/ca.pem",
      SSL_cert_file => "/path/to/client.pem",
    },
    auth_mechanism => "MONGODB-X509",
);

my $db         = $client->get_database('test');
my $collection = $db->get_collection('stuff');
my $result     = $collection->insert_one({ perlclient => 'OK!' });
my $data       = $collection->find_one({ _id => $result->inserted_id });

print "Inserted: $data\n"
# end x509 connection