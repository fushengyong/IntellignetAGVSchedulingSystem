#include "AGVBase.h"

#ifdef _AGV_BASE_H

AGVBase::AGVBase()
{
	/*!
	 * @brief 初始化AGV属性变量
	 * @date 2019-08-30
	*/
	for (unsigned char i = 0; i < 0xFF; ++i)
	{
		m_strActNameArr[i] = "";
	}

	InitializeAttribut(0, AGVType());
}


AGVBase::~AGVBase()
{
}

AGVBase::AGVBase(const unsigned short usNo, const AGVType & Type)
{
	/*!
	 * @brief 初始化AGV属性变量
	 * @date 2019-08-30
	*/
	for (unsigned char i = 0; i < 0xFF; ++i)
	{
		m_strActNameArr[i] = "";
	}

	InitializeAttribut(usNo, Type);
}

AGVBase::AGVBase(const unsigned short usNo, const AGVType & Type, const unsigned short usCurLocation, const unsigned short usEndLocation)
{
	/*!
	 * @brief 初始化AGV属性变量
	 * @date 2019-08-30
	*/
	for (unsigned char i = 0; i < 0xFF; ++i)
	{
		m_strActNameArr[i] = "";
	}

	InitializeAttribut(usNo, Type, usCurLocation, usEndLocation);
}

void AGVBase::InitializeAttribut(const unsigned short usNo, const AGVType & Type)
{
	/*!
	 * @brief 初始化AGV属性变量
	 * @date 2019-08-30
	*/
	m_usNo = usNo;
	m_Type = Type;

	m_usCurLocation = 0;
	m_usEndLocation = 0;
	m_usOldLocation = 0;
	m_usEndLocation = 0;
	m_chCurSpeed = 0;
	m_byBattery = 0;
	m_byLifter = AGVLifter::Down;
	m_byRoller = AGVRoller::Stop;
	m_usArmAction = 0;
	m_byArmStatus = AGVArmStatus::None;
	m_byStatus = AGVStatus::Wait;
	m_byCargo = 0;
	m_chError = AGVError::None;

	return;
}

void AGVBase::InitializeAttribut(const unsigned short usNo, const AGVType & Type, const unsigned short usCurLocation, const unsigned short usEndLocation)
{
	/*!
	 * @brief 初始化AGV属性变量
	 * @date 2019-08-30
	*/
	InitializeAttribut(usNo, Type);

	m_usCurLocation = usCurLocation;
	m_usEndLocation = usEndLocation;

	return;
}

void AGVBase::UpdateSpeed(const char chSpeed)
{
	/*!
	 * @brief 比较当前记录的AGV速度信息与AGV上传的速度信息是否一致
	 * 如果一致则不修改记录的信息
	 * @date 2019-08-30
	*/
	if (m_chCurSpeed == chSpeed)
	{
		return;
	}

	/*!
	 * @brief 如果不一致则修改记录的信息为AGV上传的信息
	 * @date 2019-08-30
	*/
	m_chCurSpeed = chSpeed;

	return;
}

void AGVBase::UpdateBattery(const unsigned char byBattery)
{
	/*!
	 * @brief 比较当前记录的AGV剩余电量信息与AGV上传的剩余电量信息是否一致
	 * 如果一致则不修改记录的信息
	 * @date 2019-08-30
	*/
	if (m_byBattery == byBattery)
	{
		return;
	}

	/*!
	 * @breif 如果不一致则修改记录的信息为AGV上传的信息
	 * @date 2019-08-30
	*/
	m_byBattery = byBattery;

	return;
}

void AGVBase::UpdateStatus(const unsigned char byStatus)
{
	/*!
	 * @brief 比较当前记录的AGV运行状态信息与AGV上传的运行状态信息是否一致
	 * 如果一致则不修改记录的信息
	 * @date 2019-08-30
	*/
	if (m_byStatus == byStatus)
	{
		return;
	}

	/*!
	 * @brief 如果不一致则修改记录的信息为AGV上传的信息
	 * @date 2019-08-30
	*/
	m_byStatus = byStatus;

	return;
}

void AGVBase::UpdateCargo(const unsigned char byCargo)
{
	/*!
	 * @brief 比较当前记录的AGV载货数量信息与AGV上传的载货数量信息是否一致
	 * 如果一致则不修改记录的信息
	 * @date 2019-08-30
	*/
	if (m_byCargo == byCargo)
	{
		return;
	}

	/*!
	 * @brief 如果不一致则修改记录的信息为AGV上传的信息
	 * @date 2019-08-30
	*/
	m_byCargo = byCargo;

	return;
}

void AGVBase::UpdateLifter(const unsigned char byLifter)
{
	/*!
	 * @brief 比较当前记录的AGV举升杆状态信息与AGV上传的举升杆状态信息是否一致
	 * 如果一致则不修改记录的信息
	 * @date 2019-08-30
	*/
	if (m_byLifter == byLifter)
	{
		return;
	}

	/*!
	 * @breif 如果不一致则修改记录的信息为AGV上传的信息
	 * @date 2019-08-30
	*/
	m_byLifter = byLifter;

	return;
}

void AGVBase::UpdateRoller(const unsigned char byRoller)
{
	/*!
	 * @brief 比较当前记录的AGV辊筒信息与AGV上传的辊筒信息是否一致
	 * 如果一致则不修改记录的信息
	 * @date 2019-08-30
	*/
	if (m_byRoller == byRoller)
	{
		return;
	}

	/*!
	 * @brief 如果不一致则修改记录的信息为AGV上传的信息
	 * @date 2019-08-20
	*/
	m_byRoller = byRoller;

	return;
}

void AGVBase::UpdateArmAction(const unsigned short usAction)
{
	/*!
	 * @brief 比较当前记录的机械臂动作信息与AGV上传的机械臂动作信息是否一致
	 * 如果一致则不修改记录的信息
	 * @date 2019-08-30
	*/
	if (m_usArmAction == usAction)
	{
		return;
	}

	/*!
	 * @brief 如果一致则修改记录的信息为AGV上传的信息
	 * @date 2019-08-30
	*/
	m_usArmAction = usAction;

	return;
}

void AGVBase::UpdateArmStatus(const unsigned char byStatus)
{
	/*!
	 * @brief 比较记录的机械臂当前动作的状态信息与AGV上传的机械臂当前动作的状态信息是否一致
	 * 如果一致不修改记录的信息
	 * @date 2019-08-30
	*/
	if (m_byArmStatus == byStatus)
	{
		return;
	}

	/*!
	 * @brief 如果一致修改记录的信息为AGV上传的信息
	 * @date 2019-08-30
	*/
	m_byArmStatus = byStatus;

	return;
}

const unsigned short AGVBase::UpdateCurLocation(const unsigned short usLocation)
{
	/*!
	 * @brief 比较记录的当前位置信息与AGV上传的当前位置信息是否一致
	 * 如果一致不修改记录的信息
	 * 并返回上一位置信息
	 * @date 2019-08-30
	*/
	if (m_usCurLocation == usLocation)
	{
		return m_usOldLocation;
	}

	/*!
	 * @brief 如果不一致，
	 * 修改记录的上一位置信息为记录的当前位置信息
	 * 并 修改记录的当前位置信息为AGV上传的信息
	 * 然后 返回上一位置信息
	 * @date 2019-08-30
	*/
	m_usOldLocation = m_usCurLocation;
	m_usCurLocation = usLocation;

	return m_usOldLocation;
}

const unsigned short AGVBase::UpdateEndLocation(const unsigned short usLocation)
{
	/*!
	 * @brief 比较记录的终点位置信息与AGV上传的终点位置信息是否一致
	 * 如果一致不修改记录的信息
	 * 并返回上一终点位置信息
	 * @date 2019-08-30
	*/
	if (m_usEndLocation == usLocation)
	{
		return m_usOldEndLocation;
	}

	/*!
	 * @brief 如果不一致，
	 * 修改记录的上一终点位置信息为记录的当前终点位置信息
	 * 并 修改记录的终点位置信息为AGV上传的信息
	 * 然后 返回上一终点位置信息
	 * @date 2019-08-30
	*/
	m_usOldEndLocation = m_usEndLocation;
	m_usEndLocation = usLocation;

	return m_usOldEndLocation;
}

void AGVBase::UpdateError(const char chError)
{
	/*!
	 * @brief 比较当前记录的异常状态信息是否与AGV传回的异常状态信息一致
	 * 如果一致则不修改记录的信息
	 * @date 2019-08-30 
	*/
	if (m_chError == chError)
	{
		return;
	}

	/*!
	 * @brief 如果当前记录的异常信息为上位机检测的异常，并且AGV传回的异常状态信息为无异常
	 * 则不修改记录的信息
	 * @date 2019-08-30
	*/
	if (chError == AGVError::None && m_chError < AGVError::None)
	{
		return;
	}
	
	/*!
	 * @brief 如果不一致则修改记录的信息为AGV上传的信息
	 * @date 2019-08-30
	*/
	m_chError = chError;

	return;
}

const unsigned short AGVBase::GetNo() const
{
	/*!
	 * @brief 返回AGV的编号信息
	 * @date 2019-08-30
	*/
	return m_usNo;
}

AGVType AGVBase::GetType() const
{
	/*!
	 * @brief 返回AGV的类型信息
	 * @date 2019-08-30
	*/
	return m_Type;
}

const unsigned short AGVBase::GetCurLocation() const
{
	/*!
	 * @brief 返回AGV当前位置信息
	 * @date 2019-08-30
	*/
	return m_usCurLocation;
}

const char AGVBase::GetSpeed() const
{
	/*!
	 * @brief 返回AGV当前的速度信息
	 * @date 2019-08-30
	*/
	return m_chCurSpeed;
}

const unsigned char AGVBase::GetBattery() const
{
	/*!
	 * @brief 返回AGV当前的剩余电量信息
	 * @date 2019-08-30
	*/
	return m_byBattery;
}

const unsigned char AGVBase::GetStatus() const
{
	/*!
	 * @brief 返回AGV当前的运行状态
	 * @date 2019-08-30
	*/
	return m_byStatus;
}

const char AGVBase::GetError() const
{
	/*!
	 * @brief 返回AGV当前的异常信息
	 * @date 2019-08-30
	*/
	return m_chError;
}

const unsigned char AGVBase::GetCargo() const
{
	/*!
	 * @brief 返回AGV当前的载货数量
	 * @date 2019-08-30
	*/
	return m_byCargo;
}

const unsigned short AGVBase::GetEndLocation() const
{
	/*!
	 * @brief 返回AGV当前终点位置信息
	 * @date 2019-08-30
	*/
	return m_usEndLocation;
}

string AGVBase::GetArmActionName(const unsigned char byAction)
{
	/*!
	 * @brief 返回AGV机械臂动作名
	 * @date 2019-08-30
	*/
	return m_strActNameArr[byAction];
}

const unsigned short AGVBase::GetOldLocation() const
{
	/*!
	 * @brief 返回AGV上一位置信息
	 * @date 2019-08-30
	*/
	return m_usOldLocation;
}

const unsigned short AGVBase::GetOldEndLocation() const
{
	/*!
	 * @brief 返回AGV上一终点位置信息
	 * @date 2019-08-30
	*/
	return m_usOldEndLocation;
}

const unsigned char AGVBase::GetLifter() const
{
	/*!
	 * @brief 返回AGV举升杆当前的状态信息
	 * @date 2019-08-30
	*/
	return m_byLifter;
}

const unsigned char AGVBase::GetRoller() const
{
	/*!
	 * @brief 返回AGV辊筒当前的状态信息
	 * @date 2019-08-30
	*/
	return m_byRoller;
}

const unsigned short AGVBase::GetArmAction() const
{
	/*!
	 * @brief 返回AGV机械臂当前执行的动作信息
	 * @date 2019-08-30
	*/
	return m_usArmAction;
}

const unsigned char AGVBase::GetArmStatus() const
{
	/*!
	 * @brief 返回AGV机械臂当前执行动作的状态信息
	 * @date 2019-08-30
	*/
	return m_byArmStatus;
}

void AGVBase::SetError(const char chError)
{
	/*!
	 * @brief 比较当前记录的异常状态信息是否与指定的异常状态信息一致
	 * 如果一致则不修改记录的信息
	 * @date 2019-08-30
	*/
	if (m_chError == chError)
	{
		return;
	}

	/*!
	 * @brief 如果当前记录的异常信息为AGV上传回的异常信息
	 * 则不修改记录的信息
	 * @date 2019-08-30
	*/
	if (m_chError > AGVError::None)
	{
		return;
	}

	/*!
	 * @brief 如果不一致则修改记录的信息为指定的信息
	 * @date 2019-08-30
	*/
	m_chError = chError;

	return;
}
#endif // _AGV_BASE_H