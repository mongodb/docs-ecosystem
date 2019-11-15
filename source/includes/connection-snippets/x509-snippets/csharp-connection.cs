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

var settingObjectOnlySettings = new MongoClientSettings 
{
  Credential = MongoCredential.CreateMongoX509Credential(null),
   SslSettings = new SslSettings {
    ClientCertificates = new List < X509Certificate > () {
     new X509Certificate2("client-certificate.pfx", "<your password>")
    },
   },
   UseTls = true,
   Server = new MongoServerAddress("localhost", 27017)
}
var client = new MongoClient(settingObjectOnlySettings);

  // end x509 connection


  