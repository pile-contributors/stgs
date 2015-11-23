/**
 * @file stgs.h
 * @brief Declarations for Stgs class
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_STGS_H_INCLUDE
#define GUARD_STGS_H_INCLUDE

#undef PERST_STRING
#define PERST_STRING QString

#include <stgs/stgs-config.h>
#include <perst/perst_interface.h>

QT_BEGIN_NAMESPACE
class QSettings;
QT_END_NAMESPACE

//! brief description
class STGS_EXPORT Stgs : public PerstInterface {

    int version_; /**< a number identifying the version */
    int array_index_; /**< index in current array */
    QSettings * impl_;

public:

    //! Default constructor.
    Stgs ();

    //! Destructor.
    virtual ~Stgs();

    //! Select current version.
    void
    setVersion (
            int version);

    //! Tell current version.
    int
    version () const {
        return version_;
    }


    //! Starts a group; internal state is altered.
    virtual bool
    beginGroup (
            const PERST_STRING & name);

    //! Ends a group; internal state is altered.
    virtual bool
    endGroup (
            const PERST_STRING & name = "");

    //! Starts writing an array; internal state is altered.
    virtual bool
    beginWriteArray (
            const PERST_STRING & name,
            int predicted_count = -1);

    //! Starts reading an array; internal state is altered.
    virtual int
    beginReadArray (
            const PERST_STRING & name);

    //! Ends an array; internal state is altered.
    virtual bool
    endArray (
            const PERST_STRING & name = "");

    //! Get current index of an array.
    virtual int
    arrayIndex () const;

    //! Set current index of an array.
    virtual bool
    setArrayIndex (
            int index);

    //! Tell the name of current group (arrays are also groups).
    virtual PERST_STRING
    group () const;

    //! Tell the full path of current group (arrays are also groups).
    virtual PERST_SLIST
    groupPath () const;

    //! Tell if a given key exists (relative to current group).
    virtual bool
    hasKey (
            const PERST_STRING & name);

    //! Tell if a given path exists (relative to current group).
    virtual bool
    hasKey (
            const PERST_SLIST & name);


    //! Get the string value for a key; the value type MUST be string.
    virtual PERST_STRING
    valueS (
            const PERST_STRING & name);

    //! Get the string list for a key; the value type MUST be an array of strings.
    virtual PERST_SLIST
    valueSList (
            const PERST_STRING & name);

    //! Get the integer value for a key; the value type MUST be integer.
    virtual int64_t
    valueInt (
            const PERST_STRING & name);

    //! Get the integer value for a key; the value type MUST be integer.
    virtual uint64_t
    valueUInt (
            const PERST_STRING & name);

    //! Get the real value for a key; the value type MUST be real.
    virtual double
    valueDbl (
            const PERST_STRING & name);


    //! Get the string value for a key; the value type MUST be string.
    inline PERST_STRING
    valueS (
            const PERST_STRING & name,
            const PERST_STRING & default_val) {
        if (hasKey (name)) return valueS (name);
        else return default_val;
    }

    //! Get the string list for a key; the value type MUST be an array of strings.
    inline PERST_SLIST
    valueSList (
            const PERST_STRING & name,
            const PERST_SLIST & default_val) {
        if (hasKey (name)) return valueSList (name);
        else return default_val;
    }

    //! Get the integer value for a key; the value type MUST be integer.
    inline int64_t
    valueInt (
            const PERST_STRING & name,
            int64_t default_val) {
        if (hasKey (name)) return valueInt (name);
        else return default_val;
    }

    //! Get the integer value for a key; the value type MUST be integer.
    inline uint64_t
    valueUInt (
            const PERST_STRING & name,
            uint64_t default_val) {
        if (hasKey (name)) return valueUInt (name);
        else return default_val;
    }

    //! Get the real value for a key; the value type MUST be real.
    inline double
    valueDbl (
            const PERST_STRING & name,
            double default_val) {
        if (hasKey (name)) return valueDbl (name);
        else return default_val;
    }


    //! Set the string value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            const PERST_STRING & value);

    //! Set the string list for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            const PERST_SLIST & value);

    //! Set the integer value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            int64_t value);

    //! Set the integer value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            uint64_t value);

    //! Set the integer value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            int value) {
        return setValue (name, (int64_t)value);
    }

    //! Set the real value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            double value);





    // not part of the PerstInterface



    //! Get the real value for a key; the value type MUST be real.
    inline QByteArray
    valueBA (
            const PERST_STRING & name,
            const QByteArray & default_val) {
        if (hasKey (name)) return valueBA (name);
        else return default_val;
    }

    QByteArray
    valueBA (
            const PERST_STRING & name);

    //! Set the real value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            const QByteArray & value);


    //! Get the real value for a key; the value type MUST be real.
    inline bool
    valueB (
            const PERST_STRING & name,
            bool default_val) {
        if (hasKey (name)) return valueB (name);
        else return default_val;
    }

    bool
    valueB (
            const PERST_STRING & name);

    //! Set the real value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            bool value);


protected:

private:

};

#endif // GUARD_STGS_H_INCLUDE
