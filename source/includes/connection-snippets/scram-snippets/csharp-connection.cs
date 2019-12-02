// begin scram connection
using MongoDB.Bson;
using MongoDB.Driver;
using System;
using System.IO;
using System.Threading.Tasks;
using System.Collections.Generic;
using System.Security.Cryptography.X509Certificates;

// Tested using MongoDB.Driver 2.9.2 and netcoreapp 2.2

namespace WorkingWithMongoDB
{
    class Program
    {
        static void Main(string[] args)
        {
            MainAsync().Wait();
        }

        static async Task MainAsync()
        {

            var client = new MongoClient(
                "mongodb+srv://<username>:<password>@<cluster-url>/test?retryWrites=true&w=majority"
            );
            // just doing a quick read to verify the usability of this connection
            var database = client.GetDatabase("testDB");
            var collection = database.GetCollection<BsonDocument>("testCol");
            
            var docCount = collection.CountDocuments("{}");
            Console.WriteLine(docCount);
        }
    }
}
// end scram connection