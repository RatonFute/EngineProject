#pragma once
#include <DirectXMath.h>
using namespace DirectX;
class Transform
{
public:
	XMVECTOR Scale;
	XMVECTOR Position;
	XMVECTOR Rotation;

	void UpdateMatrix();
	void Rotate(float yaw, float pitch, float roll);
	void RotateYaw(float yaw);
	void RotatePitch(float pitch);
	void RotateRoll(float roll);
private:
	float m_xPos, m_yPos, m_zPos, m_roll, m_pitch, m_yaw = 0;
	float m_xScale, m_yScale, m_zScale = 1;

	XMVECTOR m_vDir;
	XMVECTOR m_vRight;
	XMVECTOR m_vUp;

	XMMATRIX m_mRot;
	XMMATRIX m_matrix;
};
