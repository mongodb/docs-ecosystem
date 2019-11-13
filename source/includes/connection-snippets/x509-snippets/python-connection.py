# begin x509 connection
import ssl
from pymongo import MongoClient

uri = "mongodb://localmongo1/?authMechanism=MONGODB-X509"
client = MongoClient(uri,
                        ssl=True,
                        ssl_certfile='/Users/ccho/dev/drivers/certs/v3/test-client.pem',
                        ssl_cert_reqs=ssl.CERT_REQUIRED,
                        ssl_ca_certs='/Users/ccho/dev/drivers/certs/v3/test-ca.pem')

# end x509 connection