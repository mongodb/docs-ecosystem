.. note:: Placeholder Text

    You must substitute all text in quotes and angle brackets with
    your KMS configuration values.

    For example, the Node.js code prompts you to include a private key value as
    follows:

    .. code-block:: javascript
       :copyable: false

        privateKey: "<GCP service account private key>"

    Suppose your GCP service account private key is the following:

    .. codeblock:: none
       :copyable: false

       -----BEGIN PRIVATE KEY-----
       your-private-key
       -----END PRIVATE KEY-----

    Substitute the placeholder text as follows:

    .. code-block:: javascript
       :copyable: false

       privateKey: "your-private-key"
