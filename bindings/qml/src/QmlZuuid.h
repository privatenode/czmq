/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#ifndef QML_ZUUID_H
#define QML_ZUUID_H

#include <QtQml>

#include <czmq.h>
#include "qml_czmq_plugin.h"


class QmlZuuid : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isNULL READ isNULL)
    
public:
    zuuid_t *self;
    
    QmlZuuid() { self = NULL; }
    bool isNULL() { return self == NULL; }
    
    static QObject* qmlAttachedProperties(QObject* object); // defined in QmlZuuid.cpp
    
public slots:
    //  Set UUID to new supplied ZUUID_LEN-octet value.
    void set (const byte *source);

    //  Set UUID to new supplied string value skipping '-' and '{' '}'
    //  optional delimiters. Return 0 if OK, else returns -1.         
    int setStr (const QString &source);

    //  Return UUID binary data.
    const byte *data ();

    //  Return UUID binary size
    size_t size ();

    //  Returns UUID as string
    const QString str ();

    //  Return UUID in the canonical string format: 8-4-4-4-12, in lower
    //  case. Caller does not modify or free returned value. See        
    //  http://en.wikipedia.org/wiki/Universally_unique_identifier      
    const QString strCanonical ();

    //  Store UUID blob in target array
    void export (byte *target);

    //  Check if UUID is same as supplied value
    bool eq (const byte *compare);

    //  Check if UUID is different from supplied value
    bool neq (const byte *compare);

    //  Make copy of UUID object; if uuid is null, or memory was exhausted,
    //  returns null.                                                      
    QmlZuuid *dup ();
};

class QmlZuuidAttached : public QObject
{
    Q_OBJECT
    QObject* m_attached;
    
public:
    QmlZuuidAttached (QObject* attached) {
        Q_UNUSED (attached);
    };
    
public slots:
    //  Self test of this class.
    void test (bool verbose);

    //  Create a new UUID object.
    QmlZuuid *construct ();

    //  Create UUID object from supplied ZUUID_LEN-octet value.
    QmlZuuid *constructFrom (const byte *source);

    //  Destroy a specified UUID object.
    void destruct (QmlZuuid *qmlSelf);
};


QML_DECLARE_TYPEINFO(QmlZuuid, QML_HAS_ATTACHED_PROPERTIES)

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
