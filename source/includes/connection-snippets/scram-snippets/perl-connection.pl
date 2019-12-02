# begin scram connection
use MongoDB;

my $client = MongoDB->connect(
  'mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority'
);
my $collection = $client->ns('testDB.testCol');
$count = $collection->count_documents( {} );
print "document count: $count\n";
# end scram connection