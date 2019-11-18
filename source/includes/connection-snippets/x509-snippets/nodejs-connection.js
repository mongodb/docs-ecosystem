// begin x509 connection
const MongoClient = require('mongodb').MongoClient;
const fs = require('fs');

const cert = fs.readFileSync("/etc/certs/mongodb/client.pem");
const key = fs.readFileSync("/etc/certs/mongodb/client.pem");
const ca = fs.readFileSync("/etc/certs/mongodb/ca.pem");

const client = new MongoClient(`mongodb+srv://<cluster-url>?authMechanism=MONGODB-X509&ssl=true`, {
    useNewUrlParser: true,
    sslCA: ca,
    sslKey: key,
    sslCert: cert
});

client.connect(function(err, db) {
    // perform actions on the collection object
    client.close();
});
// end x509 connection