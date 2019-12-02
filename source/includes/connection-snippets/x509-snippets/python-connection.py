# begin x509 connection
from pymongo import MongoClient

uri = "mongodb+srv://<cluster-url>/?authMechanism=MONGODB-X509"
client = MongoClient(uri,
                     tls=True,
                     tlsCertificateKeyFile='/etc/certs/mongodb/client.pem',
                     tlsAllowInvalidCertificates=False)

db = client['testDB']
collection = db['testCol']
docCount = collection.count_documents({})
print(docCount)
# end x509 connection
