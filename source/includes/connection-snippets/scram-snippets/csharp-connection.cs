// begin scram connection
using MongoDB.Bson;
using MongoDB.Driver;
// ...
var client = new MongoClient(
    "mongodb+srv://<username>:<password>@<cluster-address>/test?retryWrites=true&w=majority"
);
var database = client.GetDatabase("test");
// end scram connection