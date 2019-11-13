// begin x509 connection
#include <iostream>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>

#include <mongocxx/options/client.hpp>
#include <mongocxx/options/ssl.hpp>

int main(int, char**) {
  mongocxx::instance inst{};

  mongocxx::options::ssl ssl_opts{};
  ssl_opts.ca_file("<path>/certs/test-ca.pem");
  ssl_opts.pem_file("<path>/certs/test-client.pem");

  mongocxx::options::client client_opts{};
  client_opts.ssl_opts(ssl_opts);
  string subject = "mongodb://<your_subject>";
  string uri = "@localmongo1/?authMechanism=MONGODB-X509&ssl=true";
  mongocxx::uri uri(subject + uri);

  auto client = mongocxx::client{uri, client_opts};
}
// end x509 connection