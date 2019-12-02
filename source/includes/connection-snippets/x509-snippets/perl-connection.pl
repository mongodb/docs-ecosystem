# begin x509 connection
use MongoDB;

$certificateKeyFilePath = "/etc/certs/mongodb/client.pem";
my $client = MongoDB->connect(
  'mongodb+srv://<cluster-url>/test?authSource=$external&tlsCertificateKeyFile=' . $certificateKeyFilePath . '&retryWrites=true&w=majority&authMechanism=MONGODB-X509'
);
my $collection = $client->ns('testDB.testCol');
$count = $collection->count_documents( {} );
print "Inserted: $count\n";
# end x509 connection