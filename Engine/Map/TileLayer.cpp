#include "TileLayer.h"
#include <Graphics/TextureManager.h>



TileLayer::TileLayer(int tilesize, int rowCount, int colCount, TileMap tilemap, TilesetList tilesets) 
{
	m_TileSize = tilesize;
	m_RowCount = rowCount;
	m_ColCount = colCount;
	m_Tilemap = tilemap;
	m_Tilesets = tilesets;

	for (unsigned int i = 0; i < m_Tilesets.size(); i++) {
		TextureManager::GetInstance()->Load(m_Tilesets[i].Name, "Assets/Maps/" + m_Tilesets[i].Source);
	}
}

void TileLayer::Render()
{

	for (unsigned int i = 0; i < m_RowCount; i++) {
		for (unsigned int j = 0; j < m_ColCount; j++) {
			int tileID = m_Tilemap[i][j];
			if (tileID == 0) {
				continue;
			}
			else
			{
				int index = 0;
				if (m_Tilesets.size() > 1) {
					for (unsigned int k = 1; k < m_Tilesets.size(); k++) {
						if (tileID > m_Tilesets[k].FirstID && tileID < m_Tilesets[k].LastID) {
							tileID = tileID + m_Tilesets[k].TileCount - m_Tilesets[k].LastID;
							index = k;
							break;
						}
					}
				}


				Tileset set = m_Tilesets[index];
				int tileRow = tileID / set.ColCount;
				int tileCol = tileID - tileRow * set.ColCount - 1;


				if (tileID % set.ColCount == 0) {
					tileRow--;
					tileCol = set.ColCount - 1;
				}
				TextureManager::GetInstance()->DrawTile(set.Name, set.TileSize, j*set.TileSize, i*set.TileSize, tileRow, tileCol);
			}
		}
	}
}

void TileLayer::Update()
{
}
