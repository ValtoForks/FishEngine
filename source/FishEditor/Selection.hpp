#ifndef Selection_hpp
#define Selection_hpp

#include "FishEditor.hpp"

NAMESPACE_FISHEDITOR_BEGIN

// Access to the selection in the editor.
class Selection
{
public:
    // Returns the active game object. (The one shown in the inspector).
    static std::shared_ptr<FishEngine::GameObject>
    activeGameObject() {
        return m_activeGameObject.lock();
    }

    static void
    setActiveGameObject(std::shared_ptr<FishEngine::GameObject> gameObject) {
        m_activeGameObject = gameObject;
    }
    
    static std::shared_ptr<FishEngine::GameObject>
    selectedGameObjectInHierarchy() {
        return m_selectedGameObjectInHierarchy.lock();
    }
    
    static void
    setSelectedGameObjectInHierarchy(std::shared_ptr<FishEngine::GameObject> gameObject) {
        m_selectedGameObjectInHierarchy = gameObject;
    }

private:
    //friend class EditorGUI;
    static std::weak_ptr<FishEngine::GameObject> m_activeGameObject;
    static std::weak_ptr<FishEngine::GameObject> m_selectedGameObjectInHierarchy;
};


NAMESPACE_FISHEDITOR_END

#endif // Selection_hpp
