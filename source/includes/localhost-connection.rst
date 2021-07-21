If you need to run a MongoDB server on your local machine for development
purposes instead of using an Atlas cluster, you need to complete the following:

1. Download the `Community <https://www.mongodb.com/try/download/community>`__
   or `Enterprise <https://www.mongodb.com/try/download/enterprise>`__ version
   of MongoDB Server.

#. `Install and configure <https://docs.mongodb.com/manual/installation/>`__
   MongoDB Server.

#. Start the server.

.. warning::

   Never run a MongoDB server unless you have appropriate security measures
   set up. See our :manual:`Security Checklist </administration/security-checklist/>`
   for a list of security recommendations.

After you successfully start your MongoDB server, specify your connection
string in your driver connection code.

If your MongoDB Server is running locally on its default port ``27017``, you
can use the connection string ``"mongodb://localhost"``. If you configured
your server to run on another port, use the connection string format
``"mongodb://localhost:<port>"``. If you need to specify a different hostname
or IP address, see our Server Manual entry on :manual:`Connection Strings </reference/connection-string/>`.
