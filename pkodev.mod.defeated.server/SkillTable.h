#pragma once
#include <iostream>
#include <unordered_map>
#include <optional>

namespace pkodev {

	class CSkillTable
	{
		public:
			using EffectToSkill = std::unordered_map<short int, short int>;
			using JobToTable = std::unordered_map<int, EffectToSkill>;

			const std::size_t JOB_AMOUNT = 20;
			const std::size_t EFFECTS_PER_JOB = 32;
			
			CSkillTable();
			~CSkillTable() = default;

			void SetSkill(int jobId, short int effectId, short int skillId);
			std::optional<short int> GetSkill(int jobId, short int effectId) const;

			void Clear() { m_table.clear(); }

			std::size_t JobCount() const { return m_table.size(); }
			std::size_t EffectsCount(int jobId) const;

			std::ostream& operator<<(std::ostream& out) const;

		private:
			JobToTable m_table;
	};

}

