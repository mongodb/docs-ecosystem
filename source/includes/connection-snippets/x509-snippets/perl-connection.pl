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
# end x509 connection