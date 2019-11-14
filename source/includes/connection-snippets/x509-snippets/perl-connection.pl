# begin x509 connection
use IO::Socket::SSL;
use MongoDB;

my $client = MongoDB::MongoClient->new(
    host => "mongodb://localhost",
    ssl  => {
        SSL_ca_file   => "/etc/certs/mongodb/ca.pem",
        SSL_cert_file => "/etc/certs/mongodb/client.pem",
    },
    auth_mechanism => "MONGODB-X509",
);

# end x509 connection
