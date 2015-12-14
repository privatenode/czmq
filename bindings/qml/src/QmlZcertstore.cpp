/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "QmlZcertstore.h"


///
//  Look up certificate by public key, returns zcert_t object if found,
//  else returns NULL. The public key is provided in Z85 text format.  
QmlZcert *QmlZcertstore::lookup (const QString &publicKey) {
    QmlZcert *retQ_ = new QmlZcert ();
    retQ_->self = zcertstore_lookup (self, publicKey.toUtf8().data());
    return retQ_;
};

///
//  Insert certificate into certificate store in memory. Note that this
//  does not save the certificate to disk. To do that, use zcert_save()
//  directly on the certificate. Takes ownership of zcert_t object.    
void QmlZcertstore::insert (QmlZcert *certP) {
    zcertstore_insert (self, &certP->self);
};

///
//  Print list of certificates in store to logging facility
void QmlZcertstore::print () {
    zcertstore_print (self);
};

///
//  DEPRECATED as incompatible with centralized logging
//  Print list of certificates in store to open stream 
void QmlZcertstore::fprint (FILE *file) {
    zcertstore_fprint (self, file);
};


QObject* QmlZcertstore::qmlAttachedProperties(QObject* object) {
    return new QmlZcertstoreAttached(object);
}


///
//  Self test of this class
void QmlZcertstoreAttached::test (bool verbose) {
    zcertstore_test (verbose);
};

///
//  Create a new certificate store from a disk directory, loading and        
//  indexing all certificates in that location. The directory itself may be  
//  absent, and created later, or modified at any time. The certificate store
//  is automatically refreshed on any zcertstore_lookup() call. If the       
//  location is specified as NULL, creates a pure-memory store, which you    
//  can work with by inserting certificates at runtime.                      
QmlZcertstore *QmlZcertstoreAttached::construct (const QString &location) {
    QmlZcertstore *qmlSelf = new QmlZcertstore ();
    qmlSelf->self = zcertstore_new (location.toUtf8().data());
    return qmlSelf;
};

///
//  Destroy a certificate store object in memory. Does not affect anything
//  stored on disk.                                                       
void QmlZcertstoreAttached::destruct (QmlZcertstore *qmlSelf) {
    zcertstore_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
