Starting with MongoDB 5.0, you can configure your MongoDB client
instance to use the Versioned API. The Versioned API maintains backwards
compatibility, which means that you can deploy your app and upgrade your MongoDB
server without changing any code or updating your driver. To use the
Versioned API, use the
:atlas:`Atlas connection string </driver-connection>` for your cluster
and specify the API version.