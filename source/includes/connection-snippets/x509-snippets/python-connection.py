# begin x509 connection
import ssl
from pymongo import MongoClient

uri = "mongodb+srv://<cluster-url>/?authMechanism=MONGODB-X509"
client = MongoClient(uri,
                     tls=True,
                     tlsCertificateKeyFile='/etc/certs/mongodb/client.pem',
                     tlsAllowInvalidCertificates=False)

db = client['test-database']
collection = db['test-collection']
docCount = collection.count_documents({'x': 1})
print(docCount)
# end x509 connection
