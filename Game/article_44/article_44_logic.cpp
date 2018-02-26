#include <iostream>
#include "article_44_logic.hpp"
#include "GraphicsManager.hpp"
#include "SceneManager.hpp"
#include "IPhysicsManager.hpp"

using namespace My;
using namespace std;

int article_44_logic::Initialize()
{
    int result;

    cout << "[GameLogic] Initialize" << endl;
    cout << "[GameLogic] Start Loading Game Scene" << endl;
    result = g_pSceneManager->LoadScene("Scene/study.ogex");

    return result;
}

void article_44_logic::Finalize()
{
    cout << "[GameLogic] Finalize" << endl;
}

void article_44_logic::Tick()
{

}

void article_44_logic::OnLeftKey()
{
    auto node_weak_ptr = g_pSceneManager->GetSceneGeometryNode("Suzanne");
    if(auto node_ptr = node_weak_ptr.lock())
    {
        node_ptr->RotateBy(-PI/6.0f, 0.0f, 0.0f);
        g_pPhysicsManager->UpdateRigidBodyTransform(*node_ptr);
    }
}

void article_44_logic::OnRightKey()
{
    auto node_weak_ptr = g_pSceneManager->GetSceneGeometryNode("Suzanne");
    if(auto node_ptr = node_weak_ptr.lock())
    {
        node_ptr->RotateBy(PI/6.0f, 0.0f, 0.0f);
        g_pPhysicsManager->UpdateRigidBodyTransform(*node_ptr);
    }
}

void article_44_logic::OnUpKey()
{
    auto node_weak_ptr = g_pSceneManager->GetSceneGeometryNode("Suzanne");
    if(auto node_ptr = node_weak_ptr.lock())
    {
        node_ptr->RotateBy(0.0f, 0.0f, PI/6.0f);
        g_pPhysicsManager->UpdateRigidBodyTransform(*node_ptr);
    }
}

void article_44_logic::OnDownKey()
{
    auto node_weak_ptr = g_pSceneManager->GetSceneGeometryNode("Suzanne");
    if(auto node_ptr = node_weak_ptr.lock())
    {
        node_ptr->RotateBy(0.0f, 0.0f, -PI/6.0f);
        g_pPhysicsManager->UpdateRigidBodyTransform(*node_ptr);
    }
}