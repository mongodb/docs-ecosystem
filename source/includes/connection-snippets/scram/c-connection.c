#include <mongoc/mongoc.h>

int main (int argc, char *argv[])
{
   mongoc_database_t *database;
   mongoc_client_t *client;
   bson_error_t error;
   mongoc_init ();
   // Replace the uri string with your MongoDB deployment's connection string.
   client = mongoc_client_new(
      "mongodb+srv://<connection string>"
   );
   api = mongoc_server_api_new (MONGOC_SERVER_API_V1);
   mongoc_client_set_server_api (client, api, &error);
   database = mongoc_client_get_database (client, "admin");
   mongoc_database_destroy (database);
   mongoc_client_destroy (client);
   mongoc_cleanup ();
   return 0;
}
