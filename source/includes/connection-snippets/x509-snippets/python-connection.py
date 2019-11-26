# begin x509 connection
import ssl
from pymongo import MongoClient

uri = "mongodb+srv://<cluster-url>/?authMechanism=MONGODB-X509"
client = MongoClient(uri,
                     ssl=True,
                     ssl_certfile='/etc/certs/mongodb/client.pem',
                     ssl_cert_reqs=ssl.CERT_REQUIRED)

db = client['test-database']
collection = db['test-collection']
docCount = collection.count_documents({'x': 1})
print(docCount)
# end x509 connection
