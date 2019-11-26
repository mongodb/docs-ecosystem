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
  ssl_opts.ca_file("/etc/certs/mongodb/ca.pem");
  ssl_opts.pem_file("/etc/certs/mongodb/client.pem");

  mongocxx::options::client client_opts{};
  client_opts.ssl_opts(ssl_opts);

  mongocxx::uri uri("mongodb+srv://<cluster-url>/test?authSource=$external&retryWrites=true&w=majority&authMechanism=MONGODB-X509");

  auto client = mongocxx::client{uri, client_opts};
  mongocxx::database db = client["testDB"];
  mongocxx::collection collection = db["testCol"];

  bsoncxx::builder::basic::document basic_builder{};
  basic_builder.append(kvp("", ""));
  bsoncxx::document::value filter = basic_builder.extract();
  collection.count_documents(client, filter);
}
// end x509 connection