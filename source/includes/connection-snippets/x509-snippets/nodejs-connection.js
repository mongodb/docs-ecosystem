// begin x509 connection
const MongoClient = require('mongodb').MongoClient;
const fs = require('fs');

const cert = fs.readFileSync("/etc/certs/mongodb/client.pem");
const key = fs.readFileSync("/etc/certs/mongodb/client.pem");
const ca = fs.readFileSync("/etc/certs/mongodb/ca.pem");

const client = new MongoClient(`mongodb://localhost:27017?authMechanism=MONGODB-X509&ssl=true`, {
    useNewUrlParser: true,
    sslCA: ca,
    sslKey: key,
    sslCert: cert,
});

client.connect(function(err, db) {
    const collection = client.db("test").collection("devices");
    // perform actions on the collection object
    client.close();
});
// end x509 connection