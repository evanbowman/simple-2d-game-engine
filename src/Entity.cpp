#include "Entity.hpp"

Entity::Entity(SGE_GUID handle) : m_handle(handle) {}

SGE_GUID Entity::GetId() const {
    return m_handle;
}

const Vec2& Entity::GetPosition() const {
    return m_position;
}

void Entity::SetPosition(const Vec2& position) {
    m_position = position;
}

void Entity::SetGraphicsComponent(GraphicsCompRef gfxComp) {
    m_graphicsComponent = std::move(gfxComp);
}

GraphicsComponent* Entity::GetGraphicsComponent() {
    return m_graphicsComponent.get();
}

bool Entity::HasAttribute(SGE_Attribute attrib) const {
    return m_attributes[attrib];
}

void Entity::AddAttribute(SGE_Attribute attrib) {
    m_attributes[attrib] = true;
}

void Entity::RemoveAttribute(SGE_Attribute attrib) {
    m_attributes[attrib] = false;
}

AttributeSet Entity::GetAttributeSet() const {
    return m_attributes;
}

void Entity::SetAttributeSet(AttributeSet set) {
    m_attributes = set;
}
