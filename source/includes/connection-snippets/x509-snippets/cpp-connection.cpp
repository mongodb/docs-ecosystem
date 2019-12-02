// begin x509 connection
#include <iostream>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/options/client.hpp>
#include <mongocxx/options/ssl.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>

using bsoncxx::builder::basic::kvp;

int main(int, char**) {
  mongocxx::instance inst{};

  mongocxx::options::ssl ssl_opts{};
  ssl_opts.pem_file("/etc/certs/mongodb/client.pem");

  mongocxx::options::client client_opts{};
  client_opts.ssl_opts(ssl_opts);

  mongocxx::uri uri("mongodb+srv://<cluster-url>/test?authSource=$external&retryWrites=true&w=majority&authMechanism=MONGODB-X509&tls=true");

  auto client = mongocxx::client{uri, client_opts};
  mongocxx::database db = client["testDB"];
  mongocxx::collection collection = db["testCol"];
  
  std::cout << collection.count_documents({});
}
// end x509 connection