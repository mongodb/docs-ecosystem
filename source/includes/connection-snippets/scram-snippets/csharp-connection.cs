// begin scram connection
using MongoDB.Bson;
using MongoDB.Driver;
// ...
var client = new MongoClient(
    "mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority"
);
var database = client.GetDatabase("test");
// end scram connection