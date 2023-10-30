#include "Transform.hpp"

void Transform::UpdateMatrix() 
{

	XMVECTOR quat = XMQuaternionIdentity();
	XMVECTOR quatRot = XMQuaternionIdentity();
	quat = XMQuaternionRotationAxis(m_vDir, m_roll);
	quatRot *= quat;
	quat = XMQuaternionRotationAxis(m_vRight, m_pitch);
	quatRot *= quat;
	quat = XMQuaternionRotationAxis(m_vUp, m_yaw);
	quatRot *= quat;

	m_vRot *= quatRot;

	XMMATRIX matRot;
	matRot = XMMatrixRotationQuaternion(m_vRot);
	
	matRot = XMMatrixTranspose(matRot);
	XMFLOAT3X3 f4x4Rot;
	XMStoreFloat3x3(&f4x4Rot, matRot);

	m_vRight = XMVectorSet(f4x4Rot._11, f4x4Rot._12, f4x4Rot._13,0);
	m_vUp = XMVectorSet(f4x4Rot._21, f4x4Rot._22, f4x4Rot._23,0);
	m_vDir = XMVectorSet(f4x4Rot._31, f4x4Rot._32, f4x4Rot._33,0);

	XMMATRIX mScale = XMMatrixIdentity();
	XMMATRIX mPos = XMMatrixIdentity();
	XMMATRIX mRot = XMMatrixIdentity();

	mScale = XMMatrixScaling(m_xScale, m_yScale, m_zScale);
	mPos = XMMatrixTranslation(m_xPos, m_yPos, m_zPos);
	mRot = XMMatrixRotationY(3.14f);

	m_matrix = mScale;
	m_matrix *= mRot;
	m_matrix *= mPos;

}

void Transform::Rotate(float yaw, float pitch, float roll)
{
	m_yaw = yaw;
	m_pitch = pitch;
	m_roll = roll;
}
void Transform::RotateYaw(float yaw)
{
	m_yaw = yaw;
}
void Transform::RotatePitch(float pitch)
{
	m_pitch = pitch;
}
void Transform::RotateRoll(float roll)
{
	m_roll = roll;
}