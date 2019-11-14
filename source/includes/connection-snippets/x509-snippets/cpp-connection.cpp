// begin x509 connection
#include <iostream>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/options/client.hpp>
#include <mongocxx/options/ssl.hpp>

mongocxx::instance inst {};
mongocxx::options::ssl ssl_opts {};
ssl_opts.ca_file("/etc/certs/mongodb/ca.pem");
ssl_opts.pem_file("/etc/certs/mongodb/client.pem");
mongocxx::options::client client_opts {};
client_opts.ssl_opts(ssl_opts);
string subject = "mongodb://<your_subject>"; // mongodb://CN%3DChris%2COU%3DTestClientCertificateOrgUnit%2CO%3DEducationClientCertificate%2CL%3DTestClientCertificateLocality%2CST%3DTestClientCertificateState%2CC%3DUS
string uri = "@localhost/?authMechanism=MONGODB-X509&ssl=true";
mongocxx::uri uri(subject + uri);
auto client = mongocxx::client {
  uri,
  client_opts
};
// end x509 connection