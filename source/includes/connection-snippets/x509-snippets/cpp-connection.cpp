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

  mongocxx::uri uri("mongodb://CN%3DChris%2COU%3DTestClientCertificateOrgUnit%2CO%3DEducationClientCertificate%2CL%3DTestClientCertificateLocality%2CST%3DTestClientCertificateState%2CC%3DUS@localmongo1/?authMechanism=MONGODB-X509&ssl=true");

  auto client = mongocxx::client{uri, client_opts};
  bsoncxx::builder::stream::document document{};

  auto collection = client["test"]["stuff"];
  document << "hello-cxx" << "world";

  collection.insert_one(document.view());
  auto cursor = collection.find({});

  for (auto&& doc : cursor) {
    std::cout << bsoncxx::to_json(doc) << std::endl;
  }
}
// end x509 connection