// begin x509 connection

using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Net.Security;

using MongoDB.Bson;
using MongoDB.Driver;
using MongoDB.Driver.Core;
using System;
using System.Threading.Tasks;

using System.Security.Cryptography.X509Certificates;
using System.Security.Cryptography;
using System.Security.Permissions;

namespace WorkingWithMongoDB
{
    public class Entity
    {
        public ObjectId Id { get; set; }
        public string Name { get; set; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            MainAsync().Wait();
            Console.WriteLine("done");
        }

        static async Task MainAsync()
        {
            var settingObjectOnlySettings = new MongoClientSettings 
            {
                Credential =  MongoCredential.CreateMongoX509Credential(null),
                SslSettings = new SslSettings
                {
                    ClientCertificates = new List<X509Certificate>()
                    {
                        new X509Certificate2("client-certificate.pfx", "password")
                    },
                },
                UseTls = true,
                Server = new MongoServerAddress("localmongo1", 27017),
                AllowInsecureTls = true // for testing using self-signed certs, use this option to skip validation. DO NOT USE THIS OPTION FOR PRODUCTION USES
            };

            var client = new MongoClient(settingObjectOnlySettings);
            
            // just doing a quick read + insert to verify the usability of this connection
            var database = client.GetDatabase("test");
            var collection = database.GetCollection<BsonDocument>("stuff");
            
            var allItemsInCollection = await collection.Find(new BsonDocument()).ToListAsync();
            Console.WriteLine(allItemsInCollection.Count);

            var entity = new BsonDocument {{ "count", allItemsInCollection.Count } };
            collection.InsertOne(entity);
            Console.WriteLine("wrote " + entity + " to DB");
        }
    }
}

// end x509 connection