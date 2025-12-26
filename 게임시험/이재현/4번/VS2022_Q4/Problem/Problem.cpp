#include "stdafx.h"
#include "../dxsdk/Include/d3d9.h"
#include "../dxsdk/Include/d3dx9.h"

/////////////////////////////////////////////////////////////////////////////
//
WCHAR* g_ClassName = _T("KOCCA");
WCHAR* g_WindowName = _T("KOCCA:게임국가기술자 자격검정 실기시험 : [문제4] 답안");

/////////////////////////////////////////////////////////////////////////////
// 
WCHAR g_TitleMsg[] = _T("■ [문제4] 답안 \n■ 수험번호: 202112296 \n■ 성    명: 이재현\n");

#define ROT_SPEED	0.05f

#define S_REL(p) { if(p) p->Release(); p = NULL; }
#define S_DEL(p) { if(p) delete p; p = NULL; }


/**-----------------------------------------------------------------------------
*  전역변수
*------------------------------------------------------------------------------
*/
HWND					g_hwnd = NULL;

LPDIRECT3D9             g_pD3D = NULL; // D3D 디바이스를 생성할 D3D객체변수
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; // 렌더링에 사용될 D3D디바이스
ID3DXFont* g_pFont9 = NULL;

LPD3DXMESH              g_pMesh = NULL;
D3DMATERIAL9			g_mat;
D3DXVECTOR3				g_vLightPosition = D3DXVECTOR3(-100.0f, 0.0f, -100.0f);	// 광원의 위치
D3DXVECTOR3				g_vViewPosition = D3DXVECTOR3(0.0f, 0.0f, -100.0f);		// 카메라의 위치
LPDIRECT3DTEXTURE9		g_pTexBase = NULL;		// Diffuse텍스처
LPDIRECT3DTEXTURE9		g_pTexSecond = NULL;	// Diffuse텍스처

LPDIRECT3DVERTEXDECLARATION9	g_pDecl;	/// 정점 선언정보
LPD3DXEFFECT					g_pEffect;	/// fx파일을 사용하기 위한 인터페이스

float					g_xRot = D3DX_PI / 2.0f;	/// x축 회전
float					g_yRot = 0.0f;	/// y축 회전
D3DXMATRIXA16			g_matWorld;		/// world행렬
D3DXMATRIXA16			g_matView;		/// view행렬
D3DXMATRIXA16			g_matProj;		/// projection행렬
float					g_fTime = 0.0f;

/// 셰이더에서 사용하기 위한 사용자 정점을 정의하는 구조체
D3DVERTEXELEMENT9 g_decl[] =
{
	{ 0,  0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
	{ 0, 12, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0 },
	{ 0, 24, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 },
	D3DDECL_END()
};

/**-----------------------------------------------------------------------------
* 사용중인 텍스처 정보 출력
*------------------------------------------------------------------------------
*/
void DrawTexture(float n, LPDIRECT3DTEXTURE9 pTex)
{
	struct VTX
	{
		enum { FVF = D3DFVF_XYZRHW | D3DFVF_TEX1 };
		float px, py, pz, pw;
		float tx, ty;
	};
	VTX vtx[4] =
	{
		{     n * 128, 128, 0, 1, 0, 1 },
		{     n * 128,   0, 0, 1, 0, 0 },
		{ (n + 1) * 128, 128, 0, 1, 1, 1 },
		{ (n + 1) * 128,   0, 0, 1, 1, 0 }
	};
	g_pd3dDevice->SetTexture(0, pTex);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	g_pd3dDevice->SetFVF(VTX::FVF);
	g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vtx, sizeof(VTX));
	g_pd3dDevice->SetTexture(0, NULL);
}

/**-----------------------------------------------------------------------------
* D3D초기화
*------------------------------------------------------------------------------
*/
HRESULT InitD3D(HWND hWnd)
{
	// 디바이스를 생성하기위한 D3D객체 생성
	if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	// 디바이스를 생성할 구조체
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	D3DCAPS9 caps;
	DWORD dwPSProcess;
	// 디바이스의 능력값(caps)을 읽어온다
	g_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

	// 지원하는 픽셀쉐이더 버전이 2.0이하라면 REF드라이버를, 2.0이상이면 HW드라이버를 생성한다.
	dwPSProcess = (caps.PixelShaderVersion < D3DPS_VERSION(2, 0)) ? 0 : 1;

	if (dwPSProcess)
	{
		if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
			D3DCREATE_HARDWARE_VERTEXPROCESSING,
			&d3dpp, &g_pd3dDevice)))
			return E_FAIL;
	}
	else
	{
		if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp, &g_pd3dDevice)))
			return E_FAIL;
	}

	// 기본컬링 CCW
	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	// Z버퍼기능을 켠다.
	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

	return S_OK;
}

/**-----------------------------------------------------------------------------
* 행렬 초기화
*------------------------------------------------------------------------------
*/
void InitMatrix()
{
	/// 월드행렬
	D3DXMatrixIdentity(&g_matWorld);						/// 월드행렬을 단위행렬로 설정

	/// 뷰행렬을 설정
	D3DXVECTOR3 vEyePt = g_vViewPosition;
	D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&g_matView, &vEyePt, &vLookatPt, &vUpVec);

	/// 프로젝션 행렬 설정
	D3DXMatrixPerspectiveFovLH(&g_matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
}


/**-----------------------------------------------------------------------------
* 메시 초기화
*------------------------------------------------------------------------------
*/
HRESULT InitMesh()
{
	LPD3DXMESH		pMesh;

	D3DXLoadMeshFromX(_T("Sphere.x"), D3DXMESH_SYSTEMMEM, g_pd3dDevice, NULL, NULL, NULL, NULL, &pMesh);

	pMesh->CloneMesh(pMesh->GetOptions(), g_decl, g_pd3dDevice, &g_pMesh);
	D3DXComputeNormals(g_pMesh, NULL);

	D3DXCreateTextureFromFile(g_pd3dDevice, _T("basemap.tga"), &g_pTexBase);
	D3DXCreateTextureFromFile(g_pd3dDevice, _T("boxbody-face.jpg"), &g_pTexSecond);

	return S_OK;

}

/**-----------------------------------------------------------------------------
* 셰이더 초기화
*------------------------------------------------------------------------------
*/
HRESULT InitFX()
{
	g_pd3dDevice->CreateVertexDeclaration(g_decl, &g_pDecl);

	HRESULT h;
	LPD3DXBUFFER  pBuffer;
	// simple.FX 파일을 읽어와서 ID3DXEffect인터페이스를 생성한다.
	if (FAILED(h = D3DXCreateEffectFromFile(g_pd3dDevice, _T("shader.fx"), NULL, NULL, 0, NULL, &g_pEffect, &pBuffer)))
	{
		MessageBox(NULL, _T("Shader code error"), _T("Critical"), MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

/**-----------------------------------------------------------------------------
* 재질 초기화
*------------------------------------------------------------------------------
*/
VOID InitMaterials()
{
	ZeroMemory(&g_mat, sizeof(D3DMATERIAL9));
	g_mat.Diffuse.r = g_mat.Ambient.r = 1.0f;
	g_mat.Diffuse.g = g_mat.Ambient.g = 1.0f;
	g_mat.Diffuse.b = g_mat.Ambient.b = 1.0f;
	g_mat.Diffuse.a = g_mat.Ambient.a = 1.0f;
	g_pd3dDevice->SetMaterial(&g_mat);
}

/**-----------------------------------------------------------------------------
* 리소스 초기화
*------------------------------------------------------------------------------
*/
HRESULT InitResources()
{
	InitMatrix();
	InitMesh();
	InitMaterials();

	return InitFX();
}

/**-----------------------------------------------------------------------------
* 초기화 객체들 소거
*------------------------------------------------------------------------------
*/
VOID Cleanup()
{
	S_REL(g_pTexSecond);
	S_REL(g_pTexBase);
	S_REL(g_pDecl);
	S_REL(g_pMesh);
	S_REL(g_pEffect);
	S_REL(g_pd3dDevice);
	S_REL(g_pD3D);
}

/**-----------------------------------------------------------------------------
* 셰이더 변수 설정
*------------------------------------------------------------------------------
*/
BOOL SetupShader()
{
	// 텍스처와 행렬값을 ID3DXEffect(여기서는 정점쉐이더)에 전달한다. 
	if (g_pEffect)
	{
		D3DXHANDLE	h;
		HRESULT		hResult;

		h = g_pEffect->GetParameterBySemantic(NULL, "MATRIX_WORLD");
		hResult = g_pEffect->SetMatrix(h, &g_matWorld);
		if (FAILED(hResult))
			return FALSE;

		h = g_pEffect->GetParameterBySemantic(NULL, "MATRIX_VIEW");
		hResult = g_pEffect->SetMatrix(h, &g_matView);
		if (FAILED(hResult))
			return FALSE;

		h = g_pEffect->GetParameterBySemantic(NULL, "MATRIX_PROJ");
		hResult = g_pEffect->SetMatrix(h, &g_matProj);
		if (FAILED(hResult))
			return FALSE;

		h = g_pEffect->GetParameterBySemantic(NULL, "LIGHT_POS");
		hResult = g_pEffect->SetVector(h, (D3DXVECTOR4*)&g_vLightPosition);
		if (FAILED(hResult))
			return FALSE;

		h = g_pEffect->GetParameterBySemantic(NULL, "VIEW_POS");
		hResult = g_pEffect->SetVector(h, (D3DXVECTOR4*)&g_vViewPosition);
		if (FAILED(hResult))
			return FALSE;

		h = g_pEffect->GetParameterBySemantic(NULL, "DIFFUSE_COLOR");
		hResult = g_pEffect->SetVector(h, (D3DXVECTOR4*)&g_mat.Diffuse);
		if (FAILED(hResult))
			return FALSE;

		h = g_pEffect->GetParameterBySemantic(NULL, "SPECULAR_POWER");
		hResult = g_pEffect->SetFloat(h, 32.0f);
		if (FAILED(hResult))
			return FALSE;

		h = g_pEffect->GetParameterBySemantic(NULL, "BASEMAP");
		hResult = g_pEffect->SetTexture(h, (LPDIRECT3DBASETEXTURE9)g_pTexBase);
		if (FAILED(hResult))
			return FALSE;

		h = g_pEffect->GetParameterBySemantic(NULL, "SECONDMAP");
		hResult = g_pEffect->SetTexture(h, (LPDIRECT3DBASETEXTURE9)g_pTexSecond);
		if (FAILED(hResult))
			return FALSE;

		h = g_pEffect->GetParameterBySemantic(NULL, "TIME");
		hResult = g_pEffect->SetFloat(h, g_fTime);
		if (FAILED(hResult))
			return FALSE;

	}

	return TRUE;
}

/**-----------------------------------------------------------------------------
* 애니메이션 설정
*------------------------------------------------------------------------------
*/
BOOL Animate()
{
	D3DXMATRIXA16	matX;
	D3DXMATRIXA16	matY;

	D3DXMatrixRotationX(&matX, g_xRot);
	D3DXMatrixRotationY(&matY, g_yRot);
	g_matWorld = matX * matY;

	g_fTime = (float)(GetTickCount() % 1000) / 1000.0f;

	return SetupShader();
}


/**-----------------------------------------------------------------------------
* 메시 출력
*------------------------------------------------------------------------------
*/
void DrawMesh()
{
	g_pMesh->DrawSubset(0);
}


/**-----------------------------------------------------------------------------
* 문자열 출력
*------------------------------------------------------------------------------
*/
void RenderText()
{
	if (g_pFont9 == NULL)
	{
		D3DXCreateFont(g_pd3dDevice, 18, 0, FW_BOLD, 1, FALSE,
			DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
			TEXT("Arial"), &g_pFont9);
	}

	RECT rc = { 10,10, 400,400 };
	g_pFont9->DrawText(NULL, g_TitleMsg, -1, &rc, DT_LEFT | DT_WORDBREAK, 0xFFFFFFFF);

}

/**-----------------------------------------------------------------------------
* 화면 출력
*------------------------------------------------------------------------------
*/

VOID Render()
{
	/// 후면버퍼와 Z버퍼 초기화
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	if (Animate())
	{

		/// 렌더링 시작
		if (SUCCEEDED(g_pd3dDevice->BeginScene()))
		{
			if (g_pEffect)
			{
				UINT nPass;

				/// 정점선언값과 정점 설정
				g_pd3dDevice->SetVertexDeclaration(g_pDecl);

				/// fx출력에 사용할 테크닉 선정
				g_pEffect->SetTechnique("MyShader");

				/// fx를 사용한 출력시작
				g_pEffect->Begin(&nPass, D3DXFX_DONOTSAVESTATE);

				/// PASS 개수만큼 반복출력
				for (DWORD i = 0; i < nPass; i++)
				{
					g_pEffect->BeginPass(i);
					DrawMesh();
					g_pEffect->EndPass();
				}

				/// fx를 사용한 출력종료
				g_pEffect->End();
			}

			/// fx를 사용한뒤에는 이 값을 NULL로 해야 D3D고정 파이프라인을 사용할 수 있다.
			g_pd3dDevice->SetVertexShader(NULL);
			g_pd3dDevice->SetPixelShader(NULL);

			/// 사용중인 텍스처 정보를 화면에 출력
			DrawTexture(0, g_pTexBase);
			DrawTexture(1, g_pTexSecond);

			RenderText();

			/// 렌더링 종료
			g_pd3dDevice->EndScene();
		}

		/// 후면버퍼를 보이는 화면으로 전환
		g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
	}
}




/**-----------------------------------------------------------------------------
* 윈도우 프로시져
*------------------------------------------------------------------------------
*/
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		Cleanup();
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		if (wParam == VK_LEFT) g_yRot += ROT_SPEED;
		if (wParam == VK_RIGHT) g_yRot -= ROT_SPEED;
		if (wParam == VK_UP) g_xRot -= ROT_SPEED;
		if (wParam == VK_DOWN) g_xRot += ROT_SPEED;
		if (wParam == VK_ESCAPE) PostQuitMessage(1);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}




/**-----------------------------------------------------------------------------
* 프로그램 시작점
*------------------------------------------------------------------------------
*/
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, INT)
{
	/// 윈도우 클래스 등록
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		g_ClassName, NULL };
	RegisterClassEx(&wc);

	/// 윈도우 생성
	HWND hWnd = CreateWindow(g_ClassName, g_WindowName,
		WS_OVERLAPPEDWINDOW, 100, 100, 800, 800,
		GetDesktopWindow(), NULL, wc.hInstance, NULL);

	InitD3D(hWnd);
	if (SUCCEEDED(InitResources()))
	{

		/// 윈도우 출력
		ShowWindow(hWnd, SW_SHOWDEFAULT);
		UpdateWindow(hWnd);

		/// 메시지 루프
		MSG msg;
		ZeroMemory(&msg, sizeof(msg));
		while (msg.message != WM_QUIT)
		{
			/// 메시지큐에 메시지가 있으면 메시지 처리
			if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
				/// 처리할 메시지가 없으면 Render()함수 호출
				Render();
		}
	}

	/// 등록된 클래스 소거
	UnregisterClass(g_ClassName, wc.hInstance);
	return 0;
}
