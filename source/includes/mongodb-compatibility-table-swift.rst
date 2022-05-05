.. list-table::
   :header-rows: 1
   :stub-columns: 1
   :class: compatibility-large

   * - Swift Driver Version
     - MongoDB 5.3
     - MongoDB 5.2
     - MongoDB 5.1
     - MongoDB 5.0
     - MongoDB 4.4
     - MongoDB 4.2
     - MongoDB 4.0
     - MongoDB 3.6

   * - 1.3.0 [#1.3-limitations]_
     - |checkmark|
     - |checkmark|
     - |checkmark|
     - |checkmark|
     - |checkmark|
     - |checkmark|
     - |checkmark|
     - |checkmark|

   * - 1.2.0 [#1.0-1.2-limitations]_
     - 
     - 
     -
     - |checkmark|
     - |checkmark|
     - |checkmark|
     - |checkmark|
     - |checkmark|

   * - 1.1.0 [#1.0-1.2-limitations]_
     - 
     - 
     -
     -
     - |checkmark|
     - |checkmark|
     - |checkmark|
     - |checkmark|

   * - 1.0.0 [#1.0-1.2-limitations]_
     - 
     - 
     -
     -
     - |checkmark|
     - |checkmark|
     - |checkmark|
     - |checkmark|

The Swift driver is not compatible with MongoDB server versions older than 3.6.

.. [#1.3-limitations] The 1.3 version does not include support for
   :ref:`Client-Side Field Level Encryption <ecosystem-csfle>`,
   :manual:`GridFS </core/gridfs/>`, and authentication using AWS IAM roles.

.. [#1.0-1.2-limitations] Versions 1.0 through 1.2 do not include support for
   :manual:`OCSP </core/security-transport-encryption/>`, and authentication
   using AWS IAM roles.

