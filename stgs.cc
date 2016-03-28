/**
 * @file stgs.cc
 * @brief Definitions for Stgs class.
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#include "stgs.h"
#include "stgs-private.h"
#include <QSettings>
/**
 * @class Stgs
 *
 * Detailed description.
 */
#define VER_GROUP_NAME QString("v%1").arg (version_)

/* ------------------------------------------------------------------------- */
/**
 */
Stgs::Stgs() :
    version_(-1),
    array_index_(-1),
    impl_ (new QSettings())
{
    STGS_TRACE_ENTRY;

    impl_->beginGroup (VER_GROUP_NAME);

    STGS_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 */
Stgs::~Stgs()
{
    STGS_TRACE_ENTRY;

    impl_->endGroup();
    impl_->sync ();
    delete impl_;
    STGS_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void Stgs::setVersion (int version)
{
    QStringList path;
    for (;;) {
        QString grp = impl_->group();
        if (grp.isEmpty())
            break;
        path.append (grp);
        impl_->endGroup();
    }
    version_ = version;

    if (path.isEmpty()) {
        path.append (VER_GROUP_NAME);
    } else {
        path[0] = VER_GROUP_NAME;
    }

    foreach(const QString & s, path) {
        impl_->beginGroup (s);
    }
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool Stgs::beginGroup (const PERST_STRING & name)
{
    array_index_ = -1;
    impl_->beginGroup (name);
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool Stgs::endGroup (const PERST_STRING & name)
{
    array_index_ = -1;
    impl_->endGroup();
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool Stgs::beginWriteArray (const PERST_STRING & name, int predicted_count)
{
    array_index_ = -1;
    impl_->beginWriteArray (name, predicted_count);
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
int Stgs::beginReadArray (const PERST_STRING & name)
{
    array_index_ = -1;
    return impl_->beginReadArray (name);
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool Stgs::endArray (const PERST_STRING & name)
{
    impl_->endArray ();
    array_index_ = -1;
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
int Stgs::arrayIndex () const
{
    return array_index_;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool Stgs::setArrayIndex (int index)
{
    impl_->setArrayIndex (index);
    array_index_ = index;
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
PERST_STRING Stgs::group () const
{
    return impl_->group ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
PERST_SLIST Stgs::groupPath () const
{
    QStringList path;
    for (;;) {
        QString grp = impl_->group();
        if (grp.isEmpty())
            break;
        path.append (grp);
        impl_->endGroup();
    }
    foreach(const QString & s, path) {
        impl_->beginGroup (s);
    }
    return path;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool  Stgs::hasKey (const PERST_STRING & name)
{
    return impl_->contains (name);
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool  Stgs::hasKey (const PERST_SLIST & name)
{
    QString path = name.join (QLatin1String ("/"));
    return impl_->contains (path);
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
PERST_STRING  Stgs::valueS (const PERST_STRING & name)
{
    return impl_->value(name).toString ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
PERST_SLIST  Stgs::valueSList (const PERST_STRING & name)
{
    return impl_->value(name).toStringList ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
int64_t Stgs::valueInt (const PERST_STRING & name)
{
    return impl_->value(name).toInt ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
uint64_t Stgs::valueUInt (const PERST_STRING & name)
{
    return impl_->value(name).toUInt ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
double Stgs::valueDbl (const PERST_STRING & name)
{
    return impl_->value(name).toReal ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool  Stgs::setValue (const PERST_STRING & name, const PERST_STRING & value)
{
    impl_->setValue (name, value);
    return true;
}
/* ========================================================================= */


/* ------------------------------------------------------------------------- */
bool Stgs::setValue (const PERST_STRING & name, const PERST_SLIST & value)
{
    impl_->setValue (name, value);
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool Stgs::setValue (const PERST_STRING & name, int64_t value)
{
    impl_->setValue (name, value);
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool Stgs::setValue (const PERST_STRING & name, uint64_t value)
{
    impl_->setValue (name, value);
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool Stgs::setValue (const PERST_STRING & name, double value)
{
    impl_->setValue (name, value);
    return true;
}
/* ========================================================================= */



// not part of the PerstInterface


/* ------------------------------------------------------------------------- */
bool Stgs::setValue (const PERST_STRING & name, const QByteArray & value)
{
    impl_->setValue (name, value);
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
QByteArray Stgs::valueBA (const PERST_STRING & name)
{
    return impl_->value (name).toByteArray ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool Stgs::setValue (const PERST_STRING & name, bool value)
{
    impl_->setValue (name, value);
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool Stgs::valueB (const PERST_STRING & name)
{
    return impl_->value (name).toBool ();
}
/* ========================================================================= */
