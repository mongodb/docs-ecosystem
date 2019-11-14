# begin x509 connection
import ssl
from pymongo import MongoClient

uri = "mongodb://localhost/?authMechanism=MONGODB-X509"
client = MongoClient(uri,
ssl=True,
ssl_certfile='/etc/certs/mongodb/client.pem',
ssl_cert_reqs=ssl.CERT_REQUIRED,
ssl_ca_certs='/etc/certs/mongodb/ca.pem')
# end x509 connection