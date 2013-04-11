//=============================================================================================================
/**
* @file     modulemanager.h
* @author   Christoph Dinh <chdinh@nmr.mgh.harvard.edu>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     February, 2013
*
* @section  LICENSE
*
* Copyright (C) 2013, Christoph Dinh and Matti Hamalainen. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that
* the following conditions are met:
*     * Redistributions of source code must retain the above copyright notice, this list of conditions and the
*       following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
*       the following disclaimer in the documentation and/or other materials provided with the distribution.
*     * Neither the name of the Massachusetts General Hospital nor the names of its contributors may be used
*       to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MASSACHUSETTS GENERAL HOSPITAL BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*
* @brief    Contains the declaration of the ModuleManager class.
*
*/

#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H

//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include "../mne_x_global.h"


//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QVector>
#include <QPluginLoader>


//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE MNEX
//=============================================================================================================

namespace MNEX
{


//*************************************************************************************************************
//=============================================================================================================
// FORWARD DECLARATIONS
//=============================================================================================================

class IModule;
class ISensor;
class IRTAlgorithm;
class IRTVisualization;
class IRTRecord;
class IAlert;


//=============================================================================================================
/**
* DECLARE CLASS ModuleManager
*
* @brief The ModuleManager class provides a dynamic module loader. As well as the handling of the loaded modules.
*/
class MNE_X_SHARED_EXPORT ModuleManager : public QPluginLoader
{
    Q_OBJECT

    friend class MainWindow;
    friend class ModuleDockWidget;

public:

    //=========================================================================================================
    /**
    * Constructs a ModuleManager with the given parent.
    *
    * @param [in] parent pointer to parent Object. (It's normally the default value.)
    */
    ModuleManager(QObject* parent = 0);

    //=========================================================================================================
    /**
    * Destroys the ModuleManager.
    */
    virtual ~ModuleManager();

    //=========================================================================================================
    /**
    * Loads modules from given directory.
    *
    * @param dir the module directory.
    */
    void loadModules(const QString& dir);

    //=========================================================================================================
    /**
    * Starts all modules.
    *
    * @return true if at least one ISensor module was started successfully, false otherwise.
    */
    static bool startModules();

    //=========================================================================================================
    /**
    * Starts ISensor modules
    *
    * @return true if at least one ISensor module was started successfully, false otherwise.
    */
    static bool startSensorModules();

    //=========================================================================================================
    /**
    * Starts IRTAlgorithm modules.
    */
    static void startRTAlgorithmModules();

    //=========================================================================================================
    /**
    * Starts IRTVisualization modules.
    */
    static void startRTVisualizationModules();

    //=========================================================================================================
    /**
    * Starts IRTRecord modules.
    */
    static void startRTRecordModules();

    //=========================================================================================================
    /**
    * Starts IAlert modules.
    */
    static void startAlertModules();


    //=========================================================================================================
    /**
    * Stops all modules.
    */
    static void stopModules();

    //=========================================================================================================
    /**
    * Finds index of module by name.
    *
    * @return index of module.
    * @param name the module name.
    */
    static int findByName(const QString& name);

    //=========================================================================================================
    /**
    * Returns vector containing all modules.
    *
    * @return reference to vector containing all modules.
    */
    static inline const QVector<IModule*>& getModules();

    //=========================================================================================================
    /**
    * Returns vector containing ISensor modules.
    *
    * @return reference to vector containing ISensor modules.
    */
    static inline const QVector<ISensor*>& getSensorModules();

    //=========================================================================================================
    /**
    * Returns vector containing IRTAlgorithm modules
    *
    * @return reference to vector containing IRTAlgorithm modules
    */
    static inline const QVector<IRTAlgorithm*>& getRTAlgorithmModules();

    //=========================================================================================================
    /**
    * Returns vector containing IRTVisualization modules
    *
    * @return reference to vector containing IRTVisulaiztaion modules
    */
    static inline const QVector<IRTVisualization*>& getRTVisualizationModules();

    //=========================================================================================================
    /**
    * Returns vector containing IRTRecord modules.
    *
    * @return reference to vector containing IRTRecord modules
    */
    static inline const QVector<IRTRecord*>& getRTRecordModules();

    //=========================================================================================================
    /**
    * Returns vector containing IAlert modules.
    *
    * @return reference to vector containing IAlert modules.
    */
    static inline const QVector<IAlert*>& getAlertModules();

    //=========================================================================================================
    /**
    * Returns vector containing active ISensor modules.
    *
    * @return reference to vector containing active ISensor modules.
    */
    static inline const QVector<ISensor*>& getActiveSensorModules();

    //=========================================================================================================
    /**
    * Returns vector containing active IRTAlgorithm modules.
    *
    * @return reference to vector containing active IAlgorithm modules.
    */
    static inline const QVector<IRTAlgorithm*>& getActiveRTAlgorithmModules();

    //=========================================================================================================
    /**
    * Returns vector containing active IRTAlgorithm modules.
    *
    * @return reference to vector containing active IAlgorithm modules.
    */
    static inline const QVector<IRTVisualization*>& getActiveRTVisualizationModules();

    //=========================================================================================================
    /**
    * Returns vector containing active IRTRecord modules.
    *
    * @return reference to vector containing active IRTRecord modules.
    */
    static inline const QVector<IRTRecord*>& getActiveRTRecordModules();

    //=========================================================================================================
    /**
    * Returns vector containing active IAlert modules.
    *
    * @return reference to vector containing active IAlert modules.
    */
    static inline const QVector<IAlert*>& getActiveAlertModules();

private:

    static QVector<IModule*>            s_vecModules;		/**< Holds vector of all modules. */

    static QVector<ISensor*>            s_vecSensorModules;			/**< Holds vector of all ISensor modules. */
    static QVector<IRTAlgorithm*>       s_vecRTAlgorithmModules;	/**< Holds vector of all IRTAlgorithm modules. */
    static QVector<IRTVisualization*>   s_vecRTVisualizationModules;/**< Holds vector of all IRTVisualization modules. */
    static QVector<IRTRecord*>          s_vecRTRecordModules;		/**< Holds vector of all IRTRecord modules. */
    static QVector<IAlert*>             s_vecAlertModules;			/**< Holds vector of all IAlert modules. */

    static QVector<ISensor*>            s_vecActiveSensorModules;		    /**< Holds vector of all active ISensor modules. */
    static QVector<IRTAlgorithm*>       s_vecActiveRTAlgorithmModules;	    /**< Holds vector of all active IRTAlgorithm modules. */
    static QVector<IRTVisualization*>   s_vecActiveRTVisualizationModules;  /**< Holds vector of all active IRTVisualization modules. */
    static QVector<IRTRecord*>          s_vecActiveRTRecordModules;		    /**< Holds vector of all active IRTRecord modules. */
    static QVector<IAlert*>             s_vecActiveAlertModules;		    /**< Holds vector of all active IAlert modules. */

};


//*************************************************************************************************************
//=============================================================================================================
// INLINE DEFINITIONS
//=============================================================================================================

inline const QVector<IModule*>& ModuleManager::getModules()
{
    return s_vecModules;
}


//*************************************************************************************************************

inline const QVector<ISensor*>& ModuleManager::getSensorModules()
{
    return s_vecSensorModules;
}


//*************************************************************************************************************

inline const QVector<IRTAlgorithm*>& ModuleManager::getRTAlgorithmModules()
{
    return s_vecRTAlgorithmModules;
}


//*************************************************************************************************************

inline const QVector<IRTVisualization*>& ModuleManager::getRTVisualizationModules()
{
    return s_vecRTVisualizationModules;
}


//*************************************************************************************************************

inline const QVector<IRTRecord*>& ModuleManager::getRTRecordModules()
{
    return s_vecRTRecordModules;
}


//*************************************************************************************************************

inline const QVector<IAlert*>& ModuleManager::getAlertModules()
{
    return s_vecAlertModules;
}















//*************************************************************************************************************

inline const QVector<ISensor*>& ModuleManager::getActiveSensorModules()
{
    return s_vecActiveSensorModules;
}


//*************************************************************************************************************

inline const QVector<IRTAlgorithm*>& ModuleManager::getActiveRTAlgorithmModules()
{
    return s_vecActiveRTAlgorithmModules;
}



//*************************************************************************************************************

inline const QVector<IRTVisualization*>& ModuleManager::getActiveRTVisualizationModules()
{
    return s_vecActiveRTVisualizationModules;
}


//*************************************************************************************************************

inline const QVector<IRTRecord*>& ModuleManager::getActiveRTRecordModules()
{
    return s_vecActiveRTRecordModules;
}


//*************************************************************************************************************

inline const QVector<IAlert*>& ModuleManager::getActiveAlertModules()
{
    return s_vecActiveAlertModules;
}

} // NAMESPACE

#endif // MODULEMANAGER_H