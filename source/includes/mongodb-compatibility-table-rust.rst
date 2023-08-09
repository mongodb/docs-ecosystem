.. sharedinclude:: dbx/compatibility-table-legend.rst

.. list-table::
   :header-rows: 1
   :stub-columns: 1
   :class: compatibility-large

   * - Rust Driver Version
     - MongoDB 7.0
     - MongoDB 6.0
     - MongoDB 5.0
     - MongoDB 4.4
     - MongoDB 4.2
     - MongoDB 4.0
     - MongoDB 3.6
   * - 2.6 [#2.5-2.6-limitation]_
     - ⊛
     - ✓
     - ✓
     - ✓
     - ✓
     - ✓
     - ✓
   * - 2.5 [#2.5-2.6-limitation]_
     - ⊛
     - ⊛
     - ✓
     - ✓
     - ✓
     - ✓
     - ✓
   * - 2.4 [#2.4-limitation]_
     - ⊛
     - ⊛
     - ✓
     - ✓
     - ✓
     - ✓
     - ✓
   * - 2.3 [#2.2-2.3-limitation]_
     - ⊛
     - ⊛
     - ✓
     - ✓
     - ✓
     - ✓
     - ✓
   * - 2.2 [#2.2-2.3-limitation]_
     - ⊛
     - ⊛
     - ✓
     - ✓
     - ✓
     - ✓
     - ✓
   * - 2.1 [#2.1-limitation]_
     - ⊛
     - ⊛
     - ✓
     - ✓
     - ✓
     - ✓
     - ✓
   * - 2.0 [#2.0-limitation]_
     - ⊛
     - ⊛
     - ✓
     - ✓
     - ✓
     - ✓
     - ✓

The Rust driver is not compatible with MongoDB Server versions
older than 3.6.

.. [#2.5-2.6-limitation] This Rust driver version does not support
   :manual:`OCSP </core/security-transport-encryption/#ocsp--online-certificate-status-protocol->`.

.. [#2.4-limitation] This Rust driver version does not support Decimal128
   or :manual:`OCSP </core/security-transport-encryption/#ocsp--online-certificate-status-protocol->`.

.. [#2.2-2.3-limitation] This Rust driver version does not support Decimal128,
   :ref:`Client-Side Field Level Encryption <manual-csfle-feature>`,
   :manual:`GridFS </core/gridfs/>`, or
   :manual:`OCSP </core/security-transport-encryption/#ocsp--online-certificate-status-protocol->`.

.. [#2.1-limitation] This Rust driver version does not support Decimal128,
   :ref:`Client-Side Field Level Encryption <manual-csfle-feature>`,
   :manual:`GridFS </core/gridfs/>`,
   :manual:`OCSP </core/security-transport-encryption/#ocsp--online-certificate-status-protocol->`,
   or :ref:`change streams <changeStreams>`.

.. [#2.0-limitation] This Rust driver version does not support Decimal128,
   :ref:`Client-Side Field Level Encryption <manual-csfle-feature>`,
   :manual:`GridFS </core/gridfs/>`,
   :manual:`OCSP </core/security-transport-encryption/#ocsp--online-certificate-status-protocol->`,
   :ref:`change streams <changeStreams>`,
   :manual:`Causal Consistency </core/causal-consistency-read-write-concerns>`, or
   :atlas:`Serverless Instances </create-database-deployment/#serverless-instances>`.