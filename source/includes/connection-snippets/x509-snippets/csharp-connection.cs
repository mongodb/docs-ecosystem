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
    class Program
    {
        static void Main(string[] args)
        {
            MainAsync().Wait();
            Console.WriteLine("done");
        }

        static async Task MainAsync()
        {
            var settings = new MongoClientSettings 
            {
                Credential =  MongoCredential.CreateMongoX509Credential(null),
                SslSettings = new SslSettings
                {
                    ClientCertificates = new List<X509Certificate>()
                    {
                        new X509Certificate2("/etc/certs/mongodb/client-certificate.pfx", "<pfx_passphrase>")
                    },
                },
                UseTls = true,
                Server = new MongoServerAddress("<cluster-url>")
            };

            var client = new MongoClient(settings);
        }
    }
}
// end x509 connection