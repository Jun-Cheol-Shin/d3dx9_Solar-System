//-----------------------------------------------------------------------------
// File: Matrices.cpp
//
// Desc: Now that we know how to create a device and render some 2D vertices,
//       this tutorial goes the next step and renders 3D geometry. To deal with
//       3D geometry we need to introduce the use of 4x4 Matrices to transform
//       the geometry with translations, rotations, scaling, and setting up our
//       camera.
//
//       Geometry is defined in model space. We can move it (translation),
//       rotate it (rotation), or stretch it (scaling) using a world transform.
//       The geometry is then said to be in world space. Next, we need to
//       position the camera, or eye point, somewhere to look at the geometry.
//       Another transform, via the view matrix, is used, to position and
//       rotate our view. With the geometry then in view space, our last
//       transform is the projection transform, which "projects" the 3D scene
//       into our 2D viewport.
//
//       Note that in this tutorial, we are introducing the use of D3DX, which
//       is a set of helper utilities for D3D. In this case, we are using some
//       of D3DX's useful matrix initialization functions. To use D3DX, simply
//       include <d3dx9.h> and link with d3dx9.lib.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//-----------------------------------------------------------------------------
#include "cPlanet.h"
#include "Camera.h"

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
LPDIRECT3D9             g_pD3D = NULL; // Used to create the D3DDevice
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; // Our rendering device


cPlanet* Sun = NULL;
cPlanet* Earth = NULL;
cPlanet* Moon = NULL;
cPlanet* Mercury = NULL;
cPlanet* Venus = NULL;
cPlanet* Mars = NULL;
cPlanet* Jupiter = NULL;
cPlanet* Saturn = NULL;
cPlanet* Uranus = NULL;
cPlanet* Neptune = NULL;

Camera* g_camera = new Camera();

//-----------------------------------------------------------------------------
// Name: InitD3D()
// Desc: Initializes Direct3D
//-----------------------------------------------------------------------------
HRESULT InitD3D( HWND hWnd )
{
    // Create the D3D object.
    if( NULL == ( g_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
        return E_FAIL;

    // Set up the structure used to create the D3DDevice
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp, sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_COPY;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

    // Create the D3DDevice
    if( FAILED( g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dpp, &g_pd3dDevice ) ) )
    {
        return E_FAIL;
    }

    g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
    //g_pd3dDevice->SetRenderState( D3DRS_FILLMODE, D3DFILL_WIREFRAME);
    g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
    g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

    return S_OK;
}

//-----------------------------------------------------------------------------
// Name: SetupMatrices()
// Desc: Sets up the world, view, and projection transform Matrices.
//-----------------------------------------------------------------------------

VOID SetupMatrices()
{
    D3DXMATRIX matrix;

    Sun->setMatrix(2.0f, matrix);
    Mercury->setMatrix(3.0f, matrix);
    Venus->setMatrix(2.0f, matrix);
    Earth->setMatrix(1.5f, matrix);
    Mars->setMatrix(1.0f, matrix);
    Jupiter->setMatrix(0.8f, matrix);
    Saturn->setMatrix(0.7f, matrix);
    Uranus->setMatrix(0.6f, matrix);
    Neptune->setMatrix(0.58f, matrix);

    matrix = Earth->getTransMat() * Earth->getOribtMat();
    Moon->setMatrix(5.0f, matrix);

    D3DXMATRIXA16 matProj = g_camera->getProjmat();
    g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);

    D3DXMATRIXA16 matView = g_camera->getViewmat();
    g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);
}




//-----------------------------------------------------------------------------
// Name: InitGeometry()
// Desc: Creates the scene geometry
//-----------------------------------------------------------------------------
HRESULT InitGeometry()
{
    Sun = new cPlanet(planetType::p_Sun, g_pd3dDevice, D3DXVECTOR3(0, 0, 0), 1.3f, 20);
    Mercury = new cPlanet(planetType::p_Mercury, g_pd3dDevice, D3DXVECTOR3(2.3f, 0, 0), 0.3f, 20);
    Venus = new cPlanet(planetType::p_Venus, g_pd3dDevice, D3DXVECTOR3(3.1f, 0, 0), 0.6f, 20);
    Earth = new cPlanet(planetType::p_Earth, g_pd3dDevice, D3DXVECTOR3(4.3f, 0, 0), 0.6f, 20);
    Moon = new cPlanet(planetType::p_Moon, g_pd3dDevice, D3DXVECTOR3(0.5f, 0, 0), 0.3f, 20);
    Mars = new cPlanet(planetType::p_Mars, g_pd3dDevice, D3DXVECTOR3(5.7f, 0, 0), 0.4f, 20);
    Jupiter = new cPlanet(planetType::p_Jupiter, g_pd3dDevice, D3DXVECTOR3(7.1f, 0, 0), 0.9f, 20);
    Saturn = new cPlanet(planetType::p_Saturn, g_pd3dDevice, D3DXVECTOR3(9.2f, 0, 0), 0.8f, 20);
    Uranus = new cPlanet(planetType::p_Uranus, g_pd3dDevice, D3DXVECTOR3(11.0f, 0, 0), 0.7f, 20);
    Neptune = new cPlanet(planetType::p_Neptune, g_pd3dDevice, D3DXVECTOR3(12.7f, 0, 0), 0.67f, 20);


    return S_OK;
}




//-----------------------------------------------------------------------------
// Name: Cleanup()
// Desc: Releases all previously initialized objects
//-----------------------------------------------------------------------------
VOID Cleanup()
{
    if (Sun != NULL)
        Sun->Clean();

    if (Earth != NULL)
        Earth->Clean();

    if (Moon != NULL) {
        Moon->Clean();
    }

    if (Venus != NULL)
        Venus->Clean();

    if (Mars != NULL)
        Mars->Clean();

    if (Mercury != NULL)
        Mercury->Clean();


    if (Jupiter != NULL)
        Jupiter->Clean();

    if (Saturn != NULL)
        Saturn->Clean();

    if (Uranus != NULL)
        Uranus->Clean();

    if (Neptune != NULL)
        Neptune->Clean();

    if( g_pd3dDevice != NULL )
        g_pd3dDevice->Release();

    if( g_pD3D != NULL )
        g_pD3D->Release();


    if (g_camera != NULL)
        delete g_camera;
}

VOID SetupLights()
{
    // Set up a material. The material here just has the diffuse and ambient
    // colors set to yellow. Note that only one material can be used at a time.
    D3DMATERIAL9 mtrl;
    ZeroMemory(&mtrl, sizeof(D3DMATERIAL9));

    mtrl.Diffuse.r = mtrl.Ambient.r = 1.0f;
    mtrl.Diffuse.g = mtrl.Ambient.g = 1.0f;
    mtrl.Diffuse.b = mtrl.Ambient.b = 1.0f;
    mtrl.Diffuse.a = mtrl.Ambient.a = 1.0f;

    g_pd3dDevice->SetMaterial(&mtrl);

    // Set up a white, directional light, with an oscillating direction.
    // Note that many Lights may be active at a time (but each one slows down
    // the rendering of our scene). However, here we are just using one. Also,
    // we need to set the D3DRS_LIGHTING renderstate to enable lighting
    D3DXVECTOR3 vecDir;

    D3DLIGHT9 light;
    ZeroMemory(&light, sizeof(D3DLIGHT9));
    light.Type = D3DLIGHT_SPOT;
    light.Diffuse.r = 1.0f;
    light.Diffuse.g = 1.0f;
    light.Diffuse.b = 1.0f;

    light.Theta = D3DX_PI / 4.0;
    light.Phi = D3DX_PI / 2.0;

    light.Position = D3DXVECTOR3(0, 0, 0);
    light.Range = 100.0f;
    g_pd3dDevice->SetLight(0, &light);

    g_pd3dDevice->LightEnable(0, TRUE);
    g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

    // Finally, turn on some ambient light.
    g_pd3dDevice->SetRenderState(D3DRS_AMBIENT, 0x00202020);
}



//-----------------------------------------------------------------------------
// Name: Render()
// Desc: Draws the scene
//-----------------------------------------------------------------------------
VOID Render()
{
    // Clear the backbuffer to a black color
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
        D3DCOLOR_XRGB(0, 0, 10), 1.0f, 0);

    // Begin the scene
    if( SUCCEEDED( g_pd3dDevice->BeginScene() ) )
    {

        //SetupLights();
        // Setup the world, view, and projection Matrices
        SetupMatrices();

        // End the scene
        g_pd3dDevice->EndScene();
    }

    // Present the backbuffer contents to the display
    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
}




//-----------------------------------------------------------------------------
// Name: MsgProc()
// Desc: The window's message handler
//-----------------------------------------------------------------------------
LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
        case WM_DESTROY:
            Cleanup();
            PostQuitMessage( 0 );
            return 0;
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}




//-----------------------------------------------------------------------------
// Name: WinMain()
// Desc: The application's entry point
//-----------------------------------------------------------------------------
INT WINAPI wWinMain( HINSTANCE hInst, HINSTANCE, LPWSTR, INT )
{
    UNREFERENCED_PARAMETER( hInst );

    // Register the window class
    WNDCLASSEX wc =
    {
        sizeof( WNDCLASSEX ), CS_CLASSDC, MsgProc, 0L, 0L,
        GetModuleHandle( NULL ), NULL, NULL, NULL, NULL,
        L"D3D 과제", NULL
    };
    RegisterClassEx( &wc );

    // Create the application's window
    HWND hWnd = CreateWindow( L"D3D 과제", L"게플3A 18032048 신준철",
                              WS_OVERLAPPEDWINDOW, 50, 50, 768, 768,
                              NULL, NULL, wc.hInstance, NULL );

    // Initialize Direct3D
    if( SUCCEEDED( InitD3D( hWnd ) ) )
    {
        // Create the scene geometry
        if( SUCCEEDED( InitGeometry() ) )
        {
            // Show the window
            ShowWindow( hWnd, SW_SHOWDEFAULT );
            UpdateWindow( hWnd );

            // Enter the message loop
            MSG msg;
            ZeroMemory( &msg, sizeof( msg ) );
            while( msg.message != WM_QUIT )
            {
                if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
                {
                    TranslateMessage( &msg );
                    DispatchMessage( &msg );
                }
                else
                    Render();
            }
        }
    }

    UnregisterClass( L"D3D 과제", wc.hInstance );
    return 0;
}



