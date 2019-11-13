// begin x509 connection
const MongoClient = require('mongodb').MongoClient;
const fs = require('fs');

// Read the certificates
const cert = fs.readFileSync(__dirname + "/client.pem");
const key = fs.readFileSync(__dirname + "/client.pem");
const ca = fs.readFileSync(__dirname + "/ca.pem");

const client = new MongoClient(`mongodb://localmongo1:27017?authMechanism=MONGODB-X509&ssl=true`, {
  useNewUrlParser: true,
  sslCA: ca,
  sslKey:key,
  sslCert:cert,
});

client.connect(function(err, db) {

  var dbo = db.db("test");

  dbo.collection('stuff').insertMany([
    {
      item: 'pizza',
      qty: 25,
      tags: ['pepperoni', 'tomato', 'dough'],
    },
    {
      item: 'shortrib',
      qty: 85,
      tags: ['beef'],
    }
  ], function(err, res) {
    if (err) throw err;
    console.log("docs successfully inserted into node-data");
    db.close();
  });


  client.close();
});
// end x509 connection