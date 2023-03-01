#include <mongoc/mongoc.h>

int main (int argc, char **argv)
{
   mongoc_client_t *client = NULL;
   bson_error_t error = {0};
   mongoc_server_api_t *api = NULL;
   mongoc_database_t *database = NULL;


   // Initialize the MongoDB C Driver.
   mongoc_init ();

   // Replace the connection string with your MongoDB deployment's connection string.
   client = mongoc_client_new("<connection string>");

   // Set the version of the Stable API on the client.
   api = mongoc_server_api_new (MONGOC_SERVER_API_V1);
   if (!mongoc_client_set_server_api (client, api, &error))
   {
      // Error condition.
      printf("%s", error.message);
      return 0;
   }
   
   // A not null value for 'database' here means the connection was successful.
   database = mongoc_client_get_database (client, "test");

  // Perform Cleanup.
   mongoc_database_destroy (database);
   mongoc_client_destroy (client);
   mongoc_cleanup ();

   return 0;
}

